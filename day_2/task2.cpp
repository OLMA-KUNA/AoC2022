// code of advent 5-1
#include <fstream>
#include <iostream>

const unsigned int rock = 1;
const unsigned int paper = 2;
const unsigned int siscors = 3;

const unsigned int draw = 3;
const unsigned int win = 6;

int main(int argc, char *argv[]) {
  std::fstream input;
  input.open("./input.txt", std::ios::in);
  std::string a;
  unsigned long totalScore = 0;
  unsigned int score;

  while (getline(input, a)) {
    switch (a[2]) {
    case 'X':
      score = 0;
      switch (a[0]) {

      case 'A':
        score += siscors;
        break;
      case 'B':
        score += rock;
        break;
      case 'C':
        score += paper;
        break;

      default:
        std::cout << "something went wrong";
        break;
      }
      break;
    case 'Y':
      score = draw;

      switch (a[0]) {

      case 'A':
        score += rock;
        break;
      case 'B':
        score += paper;
        break;
      case 'C':
        score += siscors;
        break;

      default:
        std::cout << "something went wrong";
        break;
      }
      break;
    case 'Z':
      score = win;

      switch (a[0]) {

      case 'A':
        score += paper;
        break;
      case 'B':
        score += siscors;
        break;
      case 'C':
        score += rock;
        break;

      default:
        std::cout << "something went wrong";
        break;
      }
      break;
    default:
      break;
    }
    totalScore += score;
  }

  std::cout << "My score is: " << totalScore << std::endl;
}