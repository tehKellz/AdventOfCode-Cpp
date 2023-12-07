#include "Template.h"

namespace tehKellz {

// REGISTER_TEST(Template);
struct Data {};

void Template::Parse(Data &data) {
  ProcessLines("2023/Day01.input", [&](const std::string &line) { /* */ });
}

void Template::Part1(const Data &data) {
  uint64_t total = 0;

  std::cout << "Part1 Total: " << total << std::endl;
}

void Template::Part2(const Data &data) {
  uint64_t total = 0;

  std::cout << "Part2 Total: " << total << std::endl;
}

void Template::Run() {
  Data data;
  Parse(data);
  Part1(data);
  Part2(data);
}

} // namespace tehKellz