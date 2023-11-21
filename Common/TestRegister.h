#pragma once

#include <memory>
#include <string>
#include <unordered_map>

namespace tehKellz {

class Test {
public:
  virtual void Run() = 0;
  virtual ~Test(){};
};

class TestManager {
public:
  static void RegisterTest(std::unique_ptr<Test> test, std::string testName);
  static void RunTests(std::string testName = "");
  static void Debug();

private:
  static std::unordered_map<std::string, std::unique_ptr<Test>> mTests;
};

#define REGISTER_TEST(name)                                                    \
  struct name##_REGISTERER {                                                   \
    name##_REGISTERER() {                                                      \
      TestManager::RegisterTest(std::make_unique<name>(), #name);              \
    }                                                                          \
  };                                                                           \
  name##_REGISTERER name##_REGISTERER_INSTANCE;

} // namespace tehKellz