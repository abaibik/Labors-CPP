/* hier */

#include "Employee.h"
#include <iostream>

/* hier */ Employee::Employee(const std::string f_n, const std::string l_n) {
  _first_name = f_n;
  _last_name = l_n;
}

void Employee::print() const {
  std::cout << _last_name << ", " << _first_name << std::endl;
}
