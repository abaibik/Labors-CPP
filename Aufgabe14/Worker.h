/* HIER */

#ifndef WORKER_H
#define WORKER_H

#include "Employee.h"
#include <string>

class Worker : public Employee /* HIER */
{
  double _hourly_earnings;
  double _hours;

public:
  Worker(const std::string, const std::string, double = 0.0, double = 0.0);
  double get_income() const;
  void print() const;
};

#endif