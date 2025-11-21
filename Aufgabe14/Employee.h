/* HIER */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

class Employee {
  std::string _first_name;
  std::string _last_name;

public:
  Employee(const std::string, const std::string);
  void print() const;
};

#endif