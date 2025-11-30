/* hier */
module;
#include <iostream>

export module Employee;

export class Employee {
  std::string _first_name;
  std::string _last_name;

public:
  Employee(const std::string f_n, const std::string l_n) { /* HIER */
    _first_name = f_n;
    _last_name = l_n;
  }
  void print() const {
    std::cout << _last_name << ", " << _first_name << std::endl;
  }
};
