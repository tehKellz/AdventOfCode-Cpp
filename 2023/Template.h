#pragma once

#include "../Common.h"

namespace tehKellz {

struct Data;

class Template : public Test {
public:
  Template() {}
  ~Template() override {}

  void Run() override;

private:
  void Parse(Data &data);
  void Part1(const Data &data);
  void Part2(const Data &data);
};

} // namespace tehKellz