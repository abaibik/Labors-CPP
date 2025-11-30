/* HIER */
module;
#include <iostream>

export module Manager;
import Employee;

export class Manager : public Employee /* hier */
{
  double _salary;

public:
  Manager(const std::string f_n, const std::string l_n, double s = 0)
      : Employee(f_n, l_n) {
    /* HIER */

    _salary = s;
  }
  double get_income() const { /* HIER */ return _salary; }
  void print() const {
    std::cout << "Manager: ";
    Employee::print();
  }
};