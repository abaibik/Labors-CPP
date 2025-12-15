#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  double d = 1.234;
  std::cout << " Nr Oct  Hex String  Fixed     Scientific " << std::endl;
  ;

  const auto default_precision{std::cout.precision()};

  for (int k = 1; k < 11; k++) {

    std::cout << std::setw(3) << k;
    std::cout << std::showbase << ' ' << std::setw(3) << std::oct << k;
    std::cout << ' ' << std::setw(4) << std::hex << k << " " << std::dec;
    std::cout << std::noshowbase << std::setfill('+') << std::left
              << std::setw(7) << std::string(k % 5 + 1, '*') << " "
              << std::setfill(' ');
    std::cout << std::showpos << std::internal << std::setw(9) << d
              << std::right << ' ';
    std::cout << std::setprecision(3) << std::uppercase << std::noshowpos
              << std::setw(10) << std::scientific << d << std::defaultfloat
              << std::nouppercase << std::setprecision(default_precision);
    d = d * -2;

    std::cout << std::endl;
  }
  return 0;
}
