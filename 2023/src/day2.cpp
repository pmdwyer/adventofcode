#include "day2.h"

#include <iostream>

#include "file.h"
#include "func.h"
#include "str.h"

namespace aoc
{
  int day2()
  {
    auto lines = aoc::get_lines("../../2023/input/d2-1.txt");
    auto games = aoc::map<std::string, struct game>(
        [](const std::string &s)
        {
          struct game current_game{};
          auto g = aoc::split(":", s);
          current_game.id = std::stoi(aoc::split(" ", aoc::trim(g[0]))[1]);
          auto rounds = aoc::split(";", g[1]);
          for (const auto &round: rounds)
          {
            auto colors = aoc::split(",", round);
            for (const auto &color: colors)
            {
              auto temp = aoc::split(" ", aoc::trim(color));
              auto amt = std::stoi(temp[0]);
              auto c = aoc::trim(temp[1]);
              if (c == "red")
              {
                current_game.r = std::max(amt, current_game.r);
              }
              else if (c == "green")
              {
                current_game.g = std::max(amt, current_game.g);
              }
              else
              {
                current_game.b = std::max(amt, current_game.b);
              }
            }
          }
          return current_game;
        },
        lines);

    auto count1 = std::accumulate(begin(games), end(games), 0, [](int s, struct game g)
    {
      if (g.r <= AMOUNTS[0] && g.g <= AMOUNTS[1] && g.b <= AMOUNTS[2])
      {
        return s + g.id;
      }
      return s;
    });
    auto count2 = std::accumulate(begin(games), end(games), 0, [](int s, struct game g)
    {
      return s + (g.r * g.g * g.b);
    });
    std::cout << count1 << " " << count2 << std::endl;
  }
}