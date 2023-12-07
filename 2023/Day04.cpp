#include "Day04.h"

namespace tehKellz {

REGISTER_TEST(Day04);

struct Card {
  mutable int matches = 0;
  mutable int numCards = 1;
};

struct Scratchers {
  std::vector<Card> cards;
};

int getNum(const char *str) {
  if (str[0] == ' ')
    return atoi(str + 1);
  if (str[1] == ' ')
    return atoi(str + 2);
  return atoi(str);
}

void Day04::Parse(Scratchers &data) {
  ProcessLines("2023/Day04.input", [&](const std::string &line) {
    // Fixed width parsing
    Card card;
    std::unordered_set<int> winningNums;
    for (int i = 0; i < 10; ++i) {
      winningNums.insert(getNum(&line[10 + (i * 3)]));
    }

    for (int i = 0; i < 25; ++i) {
      if (winningNums.count(getNum(&line[42 + (i * 3)])) != 0) {
        ++card.matches;
      }
    }
    data.cards.push_back(card);
  });
}

void Day04::Part1(const Scratchers &data) {
  uint64_t total = 0;
  for (const Card &card : data.cards) {
    if (card.matches > 0) {
      total += (1 << (card.matches - 1));
    }
  }

  std::cout << "Part1 Total: " << total << std::endl;
}

void Day04::Part2(const Scratchers &data) {
  uint64_t total = 0;
  for (int currCard = 0; currCard < data.cards.size(); ++currCard) {
    const Card &card = data.cards[currCard];

    for (int i = 1; i < (card.matches + 1); ++i) {
      data.cards[currCard + i].numCards += card.numCards;
    }
    total += card.numCards;
  }

  std::cout << "Part2 Total: " << total << std::endl;
}

void Day04::Run() {
  Scratchers data;
  Parse(data);
  Part1(data);
  Part2(data);
}

} // namespace tehKellz