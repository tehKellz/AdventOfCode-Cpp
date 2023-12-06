#include "Day02.h"

namespace tehKellz {

// REGISTER_TEST(Day02);

namespace {

/*
 * Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
 * Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
 * Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
 * Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
 * Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green
 */
struct Hand {
  uint32_t blue = 0;
  uint32_t red = 0;
  uint32_t green = 0;
};

struct Game {
  uint32_t num = 0;
  std::vector<Hand> hands;
  std::string line;
};

void ParseGames(std::vector<Game> &games) {
  ProcessLines("2023/Day02.input", [&](const std::string &line) {
    //
    std::vector<std::string> splitLine = split(line, {' ', ':', ','}, {';'});

    Game currGame;
    currGame.num = atoi(splitLine[1].c_str());
    currGame.line = line;

    Hand currHand;
    uint32_t currNum = 0;
    for (int i = 2; i < splitLine.size(); ++i) {
      if (splitLine[i] == ";") {
        currGame.hands.push_back(currHand);
        currHand = Hand();
        currNum = 0;
      } else if (splitLine[i] == "red") {
        currHand.red = currNum;
        currNum = 0;
      } else if (splitLine[i] == "green") {
        currHand.green = currNum;
        currNum = 0;
      } else if (splitLine[i] == "blue") {
        currHand.blue = currNum;
        currNum = 0;
      } else if (!splitLine[i].empty()) {
        currNum = atoi(splitLine[i].c_str());
      }
    }
    currGame.hands.push_back(currHand);

    games.push_back(currGame);
  });
}

void Part1(const std::vector<Game> games) {
  const uint32_t maxRed = 12;
  const uint32_t maxGreen = 13;
  const uint32_t maxBlue = 14;
  uint64_t total = 0;
  for (const auto &game : games) {
    bool possible = true;
    for (const auto &hand : game.hands) {
      if (hand.red > maxRed || hand.green > maxGreen || hand.blue > maxBlue) {
        possible = false;
        break;
      }
    }
    if (possible) {
      total += game.num;
    }
  }

  std::cout << "Part1 Total: " << total << std::endl;
}

void Part2(const std::vector<Game> games) {
  uint64_t total = 0;
  for (const auto &game : games) {
    Hand min;
    for (const auto &hand : game.hands) {
      if (min.red < hand.red)
        min.red = hand.red;
      if (min.green < hand.green)
        min.green = hand.green;
      if (min.blue < hand.blue)
        min.blue = hand.blue;
    }
    total += (min.red * min.blue * min.green);
  }
  std::cout << "Part2 Total: " << total << std::endl;
}

} // namespace

void Day02::Run() {
  std::vector<Game> games;
  ParseGames(games);
  Part1(games);
  Part2(games);
}

} // namespace tehKellz