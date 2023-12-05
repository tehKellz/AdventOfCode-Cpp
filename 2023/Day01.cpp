#include "Day01.h"

namespace tehKellz {

// REGISTER_TEST(Day01);

uint64_t GetCalib(const std::string &line) {
  std::string numstring;
  for (const char &c : line) {
    if (c >= '0' && c <= '9') {
      numstring += c;
      break;
    }
  }
  for (int i = line.length() - 1; i >= 0; --i) {
    const char &c = line[i];
    if (c >= '0' && c <= '9') {
      numstring += c;
      break;
    }
  }
  return atoi(numstring.c_str());
}

void Part1() {
  uint64_t total = 0;
  ProcessLines("2023/Day01.input",
               [&](const std::string &line) { total += GetCalib(line); });

  std::cout << "Part1 Total: " << total << std::endl;
}

std::string Convert(std::string input) {
  const std::map<std::string, std::string> combos = {
      {"zerone", "zeroone"},       {"oneight", "oneeight"},
      {"twone", "twoone"},         {"threeight", "threeeight"},
      {"fiveight", "fiveeight"},   {"nineight", "nineeight"},
      {"eighthree", "eightthree"}, {"eightwo", "eighttwo"}};

  // Find cases with shared letters and un-share them.
  for (const auto &iter : combos) {
    int index = input.find(iter.first);
    while (index != std::string::npos) {
      input.replace(index, iter.first.length(), iter.second);
      index = input.find(iter.first);
    }
  }

  const std::vector<std::string> nums = {"zero",  "one",  "two", "three",
                                         "four",  "five", "six", "seven",
                                         "eight", "nine"};

  for (int i = 0; i < 10; ++i) {
    int index = input.find(nums[i]);
    while (index != std::string::npos) {
      input.replace(index, nums[i].length(), std::to_string(i));
      index = input.find(nums[i]);
    }
  }
  return input;
}

void Part2() {
  uint64_t total = 0;
  ProcessLines("2023/Day01.input", [&](const std::string &line) {
    total += GetCalib(Convert(line));
  });
  std::cout << "Part2 Total: " << total << std::endl;
}

void Day01::Run() {
  Part1();
  Part2();
}

} // namespace tehKellz