// code of advent 1-2
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

bool reversSort(int i, int j) { return (i > j); }

int main(int argc, char *argv[]) {
  std::fstream input;
  input.open("./inputFile.txt", std::ios::in);
  std::string a;
  unsigned long maxEnergy = 0;
  unsigned long actualEnergy = 0;
  std::vector<unsigned int> energys;
  while (getline(input, a)) {

    try {

      actualEnergy += std::stoi(a);
    } catch (const std::invalid_argument &e) {
      energys.push_back(actualEnergy);
      actualEnergy = 0;
    }
  };
  energys.push_back(actualEnergy); // last energy must considerd

  std::sort(energys.begin(), energys.end(), reversSort);
  for (unsigned i = 0; i < 3 and i < energys.size(); i++) {
    maxEnergy += energys[i];
    std::cout << "actual energy is = " << energys[i] << std::endl;
  }
  std::cout << "Max energy is = " << maxEnergy << std::endl;
}