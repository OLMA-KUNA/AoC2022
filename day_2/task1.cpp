// code of advent 5-1
#include <fstream>
#include <iostream>

const unsigned int rock = 1;

const unsigned int paper = 2;

const unsigned int siscors = 3;

const unsigned int draw = 3;
const unsigned int win = 6;

unsigned int winScore(char opponent, char self) {
  unsigned int returnvalue = 0;
  if (('A' == opponent and 'Y' == self) or ('B' == opponent and 'Z' == self) or
      ('C' == opponent and 'X' == self)) {
    returnvalue = win;
  } else if (('A' == opponent and 'X' == self) or
             ('B' == opponent and 'Y' == self) or
             ('C' == opponent and 'Z' == self)) {
    returnvalue = draw;
  }
  return returnvalue;
}

int main(int argc, char *argv[]) {
  std::fstream input;
  input.open("./input.txt", std::ios::in);
  std::string a;
  unsigned long totalScore = 0;
  unsigned int score;

  while (getline(input, a)) {
    switch (a[2]) {
    case 'X':
      score = rock;
      break;
    case 'Y':
      score = paper;
      break;
    case 'Z':
      score = siscors;
      break;
    default:
      break;
    }
    totalScore += score + winScore(a[0], a[2]);
  }

  std::cout << totalScore << std::endl;
}