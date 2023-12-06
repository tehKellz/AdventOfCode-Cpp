#include "Day03.h"

namespace tehKellz {

REGISTER_TEST(Day03);

struct Symbol {
  char symbol = '.';
  int xOff = 0;
  int yOff = 0;
};

struct Part {
  uint32_t num = 0;
  std::vector<Symbol> symbols;
};

struct Gear {
  int x = 0;
  int y = 0;
  std::vector<uint32_t> num;
};

struct Schematic {
  char blueprint[142][142] = {{0, 0}};
  std::vector<Part> parts;
  std::vector<Gear> gears;
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
      char currChar = schematic.blueprint[y][x];
      if (isDigit(currChar)) {
        Part currPart;
        currPart.num = atoi(&schematic.blueprint[y][x]);

        int numStart = x;
        while (isDigit(schematic.blueprint[y][x++]))
          ;
        int numEnd = x - 1;
        int length = numEnd - numStart;

        for (int x1 = -1; x1 < length + 1; ++x1) {
          for (int y1 = -1; y1 < 2; ++y1) {
            char tmp = schematic.blueprint[y + y1][numStart + x1];
            if (isSymbol(tmp)) {
              currPart.symbols.push_back({tmp, x1, y1});
            }
            // is it a gear?
            if (tmp == '*') {
              // Is it already recorded?
              bool found = false;
              for (auto &gear : schematic.gears) {
                if (gear.x == numStart + x1 && gear.y == y + y1) {
                  found = true;
                  gear.num.push_back(currPart.num);
                }
              }
              if (!found) {
                Gear currGear{numStart + x1, y + y1, {currPart.num}};
                schematic.gears.push_back(currGear);
              }
            }
          }
        }
        schematic.parts.push_back(currPart);
        x = numEnd;
      }
    }
  }
}

void Day03::Part1(Schematic &schematic) {
  uint64_t total = 0;
  for (const auto &part : schematic.parts) {
    if (part.symbols.size() > 0) {
      total += part.num;
    }
  }

  std::cout << "Part1 Total: " << total << std::endl;
}

void Day03::Part2(Schematic &schematic) {
  uint64_t total = 0;
  for (const auto &gear : schematic.gears) {
    if (gear.num.size() == 2) {
      total += (gear.num[0] * gear.num[1]);
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