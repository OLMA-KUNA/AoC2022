// code of advent 4-1
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  std::fstream input;
  input.open("../day_5/input.txt", std::ios::in);
  std::string a;
  std::vector<char> data;
  std::vector<std::vector<char>> datas;
  std::vector<int> move;
  std::vector<std::vector<int>> moves;

  // data.clear();
  for (unsigned int i = 0; i < 11; i++) {
    datas.push_back(data);
    //   std::cout << i << ' ';
  }

  unsigned long totalScore = 0;
  bool cargo = true;
  bool moving = false;

  // read text file input
  while (getline(input, a)) {
    if (!cargo && a.length() > 10) {
      moving = true;
    }

    if (a.length() < 1 || a[1] == '1') {
      cargo = false;
      std::cout << 'i' << ' ';
    }
    if (cargo) {
      unsigned int stack = 0;
      for (unsigned int position = 1; position < a.length(); position += 4) {
        //  std::cout << typeid(a[position]).name();
        stack++;
        if ((char)a[position] != ' ') {
          datas[stack].insert(datas[stack].begin(), (char)a[position]);
        }
      }
    } else if (moving) {
      move.clear();
      move.push_back(
          std::stoi(a.substr(a.find("move ") + 5, a.find(" from") - 5)));
      move.push_back(
          std::stoi(a.substr(a.find("from ") + 5, a.find(" from") - 5)));
      move.push_back(std::stoi(a.substr(a.length() - 2)));
      moves.push_back(move);
    }
  }

  for (auto d : datas) {
    for (auto c : d) {
      std::cout << c << '-';
    }
    std::cout << std::endl;
  }

  for (auto m : moves) {
    std::cout << m[1] << '-' << std::endl;
    data.clear();
    for (unsigned int count = 0; count < m[0]; count++) {
      data.push_back(datas[m[1]].back());
      datas[m[1]].pop_back();
    }
    for (unsigned int count = 0; count < m[0]; count++) {
      datas[m[2]].push_back(data.back());
      data.pop_back();
    }
    for (auto d : datas) {
      for (auto c : d) {
        std::cout << c;
      }
      std::cout << std::endl;
    }
  }

  for (auto d : datas) {
    for (auto c : d) {
      std::cout << c;
    }
    std::cout << std::endl;
  }

  std::cout << std::endl << totalScore << std::endl;
}
