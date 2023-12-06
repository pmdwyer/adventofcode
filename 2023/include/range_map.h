#ifndef ADVENTOFCODE_RANGE_MAP_H
#define ADVENTOFCODE_RANGE_MAP_H

namespace aoc
{
  template <class T>
  class range_map
  {
  public:
    range_map() = default;
    ~range_map();

    T operator[](T n) const;
    void insert(T source, T dest, T range);

  private:
    struct node {
      T source;
      T dest;
      T range;
      struct node *left;
      struct node *right;
    };

    struct node *root = nullptr;

    static void make_node(struct node** node, T source, T dest, T range);
    void remove(struct node* node);
  };

  template <class T>
  range_map<T>::~range_map() {
    remove(root);
  }

  template <class T>
  void range_map<T>::remove(struct node* node) {
    if (!node) {
      return;
    }
    if (node->left) {
      remove(node->left);
    }
    if (node->right) {
      remove(node->right);
    }
    delete node;
  }

  template <class T>
  void range_map<T>::insert(T source, T dest, T range) {
    if (!root) {
      make_node(&root, source, dest, range);
      return;
    }
    auto *node = root;
    while ((source < node->source && node->left != nullptr)
           ||   (source >= node->source && node->right != nullptr)) {
      node = (source < node->source ? node->left : node->right);
    }
    if (source < node->source) {
      make_node(&node->left, source, dest, range);
    } else {
      make_node(&node->right, source, dest, range);
    }
  }

  template <class T>
  T range_map<T>::operator[](T n) const {
    auto *node = root;
    while (node && (n < node->source || n > node->source + node->range)) {
      node = (n < node->source ? node->left : node->right);
    }
    if (node) {
      return node->dest + (n - node->source);
    }
    return n;
  }

  template <class T>
  void range_map<T>::make_node(struct node** node, T source, T dest, T range) {
    *node = new struct node;
    (*node)->source = source;
    (*node)->dest = dest;
    (*node)->range = range;
    (*node)->left = nullptr;
    (*node)->right = nullptr;
  }
}

#endif //ADVENTOFCODE_RANGE_MAP_H
