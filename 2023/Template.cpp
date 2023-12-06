#include "Template.h"

namespace tehKellz {

// REGISTER_TEST(Template);

void Template::Parse() {
  ProcessLines("2023/Day01.input", [&](const std::string &line) { /* */ });
}

void Template::Part1() {
  uint64_t total = 0;

  std::cout << "Part1 Total: " << total << std::endl;
}

void Template::Part2() {
  uint64_t total = 0;

  std::cout << "Part2 Total: " << total << std::endl;
}

void Template::Run() {
  Parse();
  Part1();
  Part2();
}

} // namespace tehKellz