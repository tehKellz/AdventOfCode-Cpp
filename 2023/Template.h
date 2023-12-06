#pragma once

#include "../Common.h"

namespace tehKellz {

class Template : public Test {
public:
  Template() {}
  ~Template() override {}

  void Run() override;

private:
  void Parse();
  void Part1();
  void Part2();
};

} // namespace tehKellz