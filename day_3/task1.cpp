// code of advent 3-1
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  std::fstream input;
  input.open("./input.txt", std::ios::in);
  std::string a;
  std::vector<char> backpackContent;

  std::vector<char> items;

  unsigned long totalScore = 0;
  unsigned int score = 0;

  while (getline(input, a)) {
    for (int i = 0; i < a.length(); i++) {
      backpackContent.push_back(a[i]);
    }
    for (char x : backpackContent) {
      //  std::cout << x;
    }
    // std::cout << std::endl;
    bool found = false;
    char item = '9';
    for (int i = 0; i < a.length() / 2; i++) {
      auto position =
          std::find(backpackContent.begin() + backpackContent.size() / 2,
                    backpackContent.end(), backpackContent[i]);
      if (position != backpackContent.end()) {
        items.push_back(backpackContent[i]);
        found = true;
        break;
      }
    }
    if (!found) {
      std::cout << "not found error" << std::endl;
    }
    backpackContent.clear();
  }

  for (char x : items) {
    if (x <= 'Z') {
      score = x - 'A' + 27;
      std::cout << "bad";

    } else {
      score = x - 'a' + 1;
    }
    totalScore += score;
    std::cout << ' ' << score << std::endl;
  }
  std::cout << std::endl << totalScore << std::endl;
}