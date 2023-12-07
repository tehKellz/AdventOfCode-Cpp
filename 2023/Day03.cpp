#include "Day03.h"

namespace tehKellz {

// REGISTER_TEST(Day03);

struct Gear {
  std::vector<uint32_t> parts;
};

struct Schematic {
  char blueprint[142][142] = {{0, 0}};
  std::vector<int> parts;
  std::unordered_map<uint32_t, Gear> gears;
};

bool isDigit(char c) { return (c >= '0' && c <= '9'); }
bool isSymbol(char c) { return !isDigit(c) && c != 0 && c != '.'; }

void Day03::Parse(Schematic &schematic) {
  // load the data into the blueprint
  int lineNum = 0;
  ProcessLines("2023/Day03.input", [&](const std::string &line) {
    ++lineNum;
    for (int i = 0; i < line.size(); ++i) {
      schematic.blueprint[lineNum][i + 1] = line[i];
    }
  });

  // find parts in the blueprint
  for (int y = 1; y < 141; ++y) {
    for (int x = 1; x < 141; ++x) {
      if (!isDigit(schematic.blueprint[y][x]))
        continue;

      int numStart = x;
      bool nearSymbols = false;
      int partNum = atoi(&schematic.blueprint[y][numStart]);

      while (isDigit(schematic.blueprint[y][x++]))
        ;
      --x;
      int length = x - numStart;

      for (int x1 = -1; x1 < length + 1; ++x1) {
        for (int y1 = -1; y1 < 2; ++y1) {
          char tmp = schematic.blueprint[y + y1][numStart + x1];
          nearSymbols |= isSymbol(tmp);

          // is it a gear?
          if (tmp == '*') {
            uint32_t gearId = (numStart + x1) + (1000 * (y + y1));
            schematic.gears[gearId].parts.push_back(partNum);
          }
        }
      }
      if (nearSymbols)
        schematic.parts.push_back(partNum);
    }
  }
}

void Day03::Part1(Schematic &schematic) {
  uint64_t total = 0;
  for (const auto &partNum : schematic.parts) {
    total += partNum;
  }

  std::cout << "Part1 Total: " << total << std::endl;
}

void Day03::Part2(Schematic &schematic) {
  uint64_t total = 0;
  for (const auto &gear : schematic.gears) {
    if (gear.second.parts.size() == 2) {
      total += (gear.second.parts[0] * gear.second.parts[1]);
    }
  }

  std::cout << "Part2 Total: " << total << std::endl;
}

void Day03::Run() {
  Schematic schematic;
  Parse(schematic);
  Part1(schematic);
  Part2(schematic);
}

} // namespace tehKellz