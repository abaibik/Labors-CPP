/* HIER */
module;
#include <iostream>

export module Worker;
import Employee;

/* hier */ export class Worker : public Employee /* hier */
{
  double _hourly_earnings;
  double _hours;

public:
  Worker(const std::string f_n, const std::string l_n, double h_e = 0.0,
         double h = 0.0)
      : Employee(f_n, l_n) {
    /* HIER */
    _hourly_earnings = h_e;
    _hours = h;
  }

  double get_income() const { /* HIER */ return _hourly_earnings * _hours; }

  void print() const {
    std::cout << "Worker: ";
    Employee::print();
  }
};