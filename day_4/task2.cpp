// code of advent 4-2
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  std::fstream input;
  input.open("./input.txt", std::ios::in);
  std::string a;
  std::vector<int> data;
  std::vector<std::vector<int>> datas;
  std::vector<int> items;

  unsigned long totalScore = 0;
  unsigned int score = 0;

  // read text file input
  while (getline(input, a)) {
    data.clear();
    std::string delimiter = ",";
    std::string delimiterSub = "-";
    std::string s1 = a.substr(0, a.find(delimiter));

    std::string s2 = a.substr(a.find(delimiter) + 1);
    std::string s1s = s1.substr(0, s1.find(delimiterSub));
    std::string s1e = s1.substr(s1.find(delimiterSub) + 1);

    std::string s2s = s2.substr(0, s2.find(delimiterSub));
    std::string s2e = s2.substr(s2.find(delimiterSub) + 1);

    // std::cout << s1s << ':' << s1e << ' ' << s2s << ':' << s2e << std::endl;
    data.push_back(stoi(s1s));
    data.push_back(stoi(s1e));
    data.push_back(stoi(s2s));
    data.push_back(stoi(s2e));
    // datas.push_back(data);
    // }

    // use datas
    // for (data : datas) {

    std::cout << data[0] << ':' << data[1] << ' ' << data[2] << ':' << data[3]
              << std::endl;
    if (data[0] >= data[2] && data[0] <= data[3] ||
        data[1] >= data[2] && data[0] <= data[3]) {
      totalScore++;

      //  std::cout << "data0 " << std::endl;

    } else if (data[2] >= data[0] && data[2] <= data[1] ||
               data[3] >= data[0] && data[3] <= data[1]) {
      totalScore++;
      // std::cout << "data1 " << std::endl;
    }
  }

  // solution output:
  std::cout << std::endl << totalScore << std::endl;
}