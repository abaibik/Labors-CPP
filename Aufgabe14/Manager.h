/* HIER */

#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"
#include <string>

class Manager : public Employee /* HIER */
{
  double _salary;

public:
  Manager(const std::string, const std::string, double);
  double get_income() const;
  void print() const;
};

#endif