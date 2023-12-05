#pragma once

#include "../Common.h"
// #include "chrono_io"
#include <chrono>

namespace tehKellz {

typedef std::chrono::high_resolution_clock Clock;
template <typename FUNC> void ProcessLines(std::string fileName, FUNC func) {

  auto start = Clock::now();

  std::ifstream input(fileName);
  std::string line;
  while (std::getline(input, line)) {
    func(line);
  }
  input.close();

  auto end = Clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::microseconds>(end - start)
          .count();
  std::cout << " [" << duration << "us] > ";
}

std::vector<std::string> split(const std::string &input,
                               const std::unordered_set<char> delims,
                               const std::unordered_set<char> keep);
} // namespace tehKellz