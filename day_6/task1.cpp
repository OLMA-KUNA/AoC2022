// code of advent 6-1
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  std::fstream input;
  input.open("./input.txt", std::ios::in);
  std::string a;
  std::vector<char> data;
  std::vector<char> test;

  unsigned long totalScore = 0;
  bool cargo = true;
  bool moving = false;

  while (getline(input, a)) {
    for (char c : a) {
      data.push_back(c);
    }
  }

  for (unsigned int position = 0; position < a.length(); position++) {
    test.clear();
    for (unsigned int i = 0; i < 4; i++) {
      test.push_back(data[position + i]);
    }
    for (char x : test) {
      std::cout << x << ':';
    }
    std::cout << std::endl;
    std::sort(test.begin(), test.end());
    auto it = std::unique(test.begin(), test.end());
    bool wasUnique = (it == test.end());
    if (wasUnique) {
      std::cout << std::endl << position + 4 << std::endl;
      break;
    }
  }
}
