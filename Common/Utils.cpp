#include "Utils.h"

namespace tehKellz {
std::vector<std::string> split(const std::string &input,
                               const std::unordered_set<char> delims,
                               const std::unordered_set<char> keep) {
  std::vector<std::string> result;
  int last = 0;
  for (int i = 0; i < input.length(); i++) {
    if (delims.find(input[i]) != delims.end()) {
      result.push_back(input.substr(last, i - last));
      last = i + 1;
    }
    if (keep.find(input[i]) != keep.end()) {
      result.push_back(input.substr(last, i - last));
      result.push_back(input.substr(i, 1));
      last = i + 1;
    }
  }
  result.push_back(input.substr(last));
  return result;
}
} // namespace tehKellz