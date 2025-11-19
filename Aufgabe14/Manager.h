/* HIER */

#pragma once
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