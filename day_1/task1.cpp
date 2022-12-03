// code of advent 5-1
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
  std::fstream input;
  input.open("./inputFile.txt", std::ios::in);
  std::string a;
  unsigned long maxEnergy = 0;
  unsigned long actualEnergy = 0;
  while (getline(input, a)) {

    try {

      actualEnergy += std::stoi(a);
    } catch (const std::invalid_argument &e) {
      (actualEnergy > maxEnergy) ? maxEnergy = actualEnergy : true;
      actualEnergy = 0;
    }
    (actualEnergy > maxEnergy) ? maxEnergy = actualEnergy
                               : true; // last energy must considerd
  }
  std::cout << "Max energy is = " << maxEnergy << std::endl;
}