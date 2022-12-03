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
  std::vector<std::vector<char>> backpackContents;

  std::vector<char> items;

  unsigned long totalScore = 0;
  unsigned int score = 0;

  while (getline(input, a)) {
    backpackContent.clear();
    for (int i = 0; i < a.length(); i++) {
      backpackContent.push_back(a[i]);
    }
    backpackContents.push_back(backpackContent);
  }

  for (int j = 0; j < backpackContents.size(); j += 3) {
    auto content = backpackContents[j];
    auto content1 = backpackContents[j + 1];
    auto content2 = backpackContents[j + 2];
    bool found = false;

    for (int i = 0; i < content.size(); i++) {

      int position1 = std::find(content1.begin(), content1.end(), content[i]) -
                      content1.begin();
      int position2 = std::find(content2.begin(), content2.end(), content[i]) -
                      content2.begin();
      if (position1 < content1.size() && position2 < content2.size()) {
        items.push_back(content[i]);
        found = true;
        break;
      }
    }
    if (!found) {
      // std::cout << "not found error" << j << std::endl;
      for (int count = j; count < j + 3; count++) {
        for (char chara : backpackContents[count]) {
          std::cout << chara;
        }
        std::cout << std::endl;
      }
      std::cout << std::endl;
    }
    backpackContent.clear();
  }
  std::cout << items.size();
  for (char x : items) {
    std::cout << x;
    if (x <= 'Z') {
      score = x - 'A' + 27;

    } else {
      score = x - 'a' + 1;
    }
    totalScore += score;
    // std::cout << ' ' << score << std::endl;
  }
  std::cout << std::endl << totalScore << std::endl;
}