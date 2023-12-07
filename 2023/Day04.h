#pragma once

#include "../Common.h"

namespace tehKellz {

struct Scratchers;

class Day04 : public Test {
public:
  Day04() {}
  ~Day04() override {}

  void Run() override;

private:
  void Parse(Scratchers &data);
  void Part1(const Scratchers &data);
  void Part2(const Scratchers &data);
};

} // namespace tehKellz