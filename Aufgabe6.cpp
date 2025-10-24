#include <iostream>
#include <string>

class Student {
private:
  std::string _name;
  std::string _first_name;

public:
  Student(const std::string &name, const std::string &first_name);

  ~Student();

  const std::string &get_name() const;

  const std::string &get_first_name() const;

  void print(const bool with_new_line) const;

  void print() const;
};

Student::Student(const std::string &name, const std::string &first_name) {
  _name = name;
  _first_name = first_name;

  std::cout << "Parametrisierter Konstruktor Student: " << _first_name << ' '
            << _name << std::endl;
}

Student::~Student() {
  std::cout << "Destruktor Student: " << _first_name << ' ' << _name
            << std::endl;
}

const std::string &Student::get_name() const { return _name; }

const std::string &Student::get_first_name() const { return _first_name; }

void Student::print(const bool with_new_line) const {
  std::cout << "print() mit Parameter; Student: " << _first_name << ' '
            << _name;
  if (with_new_line) {
    std::cout << std::endl;
  }
}

void Student::print() const {
  std::cout << "print() ohne Parameter; Student: " << _first_name << ' '
            << _name << std::endl;
}

class Employee {
private:
  std::string _name;
  std::string _first_name;

public:
  Employee(const std::string &name, const std::string &first_name)
      : _name(name), _first_name(first_name) {
    std::cout << "Parametrisierter Konstruktor Employee: " << _first_name << ' '
              << _name << std::endl;
  }

  Employee() : Employee("Mustermann", "Erika") {
    std::cout << "Standardkonstruktor Employee: " << _first_name << ' ' << _name
              << std::endl;
  }

  Employee(const Student &student)
      : _name(student.get_name()), _first_name(student.get_first_name()) {
    std::cout << "Konvertierungskonstruktor Employee: " << _first_name << ' '
              << _name << std::endl;
  }

  ~Employee() {
    std::cout << "Destruktor Employee: " << _first_name << ' ' << _name
              << std::endl;
  }

  void print(const bool with_new_line) const {
    std::cout << "print() mit Parameter; Mitarbeiter: " << _first_name << ' '
              << _name;
    if (with_new_line) {
      std::cout << std::endl;
    }
  }

  void print() const {
    std::cout << "print() ohne Parameter; Mitarbeiter: " << _first_name << ' '
              << _name << std::endl;
  }
};

int main(int argc, char *argv[]) {
  Student stud_mustermann = Student("Mustermann", "Max");
  Employee empl_mustermann = Employee(stud_mustermann);
  Employee mit_default = Employee();
  stud_mustermann.print();
  stud_mustermann.print(true);
  empl_mustermann.print();
  mit_default.print();
  Student *p_stud_mustermann = nullptr;
  std::cout << "Block wird betreten" << std::endl;
  {
    p_stud_mustermann = new Student("Mustermann", "Markus");
    p_stud_mustermann->print(true);
  }
  std::cout << "Block wurde verlassen" << std::endl;
  delete p_stud_mustermann;
  return 0;
}
