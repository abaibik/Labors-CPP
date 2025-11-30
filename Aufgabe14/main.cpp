#include <iostream>

/* hier */

import Manager;
import Worker;

int main() {
  Manager m("Gerd", "Mayer", 1000.00);
  m.print();
  std::cout << "Gehalt: " << m.get_income() << std::endl << std::endl;
  Worker w("Aleksandra", "Baibik", 15.00, 40);
  w.print();
  std::cout << "Lohn: " << w.get_income() << std::endl;
  return 0;
}