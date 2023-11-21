#include "TestRegister.h"

#include "iostream"

namespace tehKellz {

/* static */
std::unordered_map<std::string, std::unique_ptr<Test>> TestManager::mTests;

// static
void TestManager::RegisterTest(std::unique_ptr<Test> test, std::string name) {
  mTests[name] = std::move(test);
}

// static
void TestManager::RunTests(std::string testName /* = "" */) {
  if (!testName.empty()) {
    if (mTests.count(testName) > 0) {
      mTests[testName]->Run();
    }
  } else if (!mTests.empty()) {
    for (auto &test : mTests) {
      std::cout << "----------------------------------------" << std::endl;
      std::cout << "Running test " << test.first << std::endl;
      test.second->Run();
    }
  } else {
    std::cout << "No tests registered." << std::endl;
  }
}

// static
void TestManager::Debug() {
  std::cout << "There are " << mTests.size() << " tests registered."
            << std::endl;
  int i = 0;
  for (const auto &test : mTests) {
    std::cout << "  " << ++i << " " << test.first << " : " << std::hex
              << &test.second << std::endl;
  }
}

} // namespace tehKellz