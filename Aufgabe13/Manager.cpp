/* HIER */

#include "Manager.h"
#include <iostream>

Manager::Manager(const std::string f_n, const std::string l_n, double s = 0)
    : Employee(f_n, l_n) {
  /* HIER */

  _salary = s;
}
double Manager::get_income() const { /* HIER */ return _salary; }
void Manager::print() const {
  std::cout << "Manager: ";
  Employee::print();
}