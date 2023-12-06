#pragma once

#include "../Common.h"

namespace tehKellz {

struct Schematic;

class Day03 : public Test {
public:
  Day03() {}
  ~Day03() override {}

  void Run() override;

private:
  void Parse(Schematic &schematic);
  void Part1(Schematic &schematic);
  void Part2(Schematic &schematic);
};

} // namespace tehKellz