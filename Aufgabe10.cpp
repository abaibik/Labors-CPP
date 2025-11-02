#include <iostream>
#include <string>

class Person {
  std::string _name;
  int _check_out_duration;

public:
  Person(std::string name, int check_out_duration = 0)
      : _name(name), _check_out_duration(check_out_duration) {};

  int get_check_out_duration() const { return _check_out_duration; };

  void print() const { std::cout << _name; };
};

class Lecturer : public Person {
  int _examiner_id;

public:
  Lecturer(std::string name, int examiner_id)
      : Person(name, 90), _examiner_id(examiner_id) {};
  void print() const {
    Person::print();
    std::cout << ", Prüfernummer " << _examiner_id << std::endl;
  };
};

class Student : public Person {
  int _matriculation_number;

public:
  Student(std::string name, int matriculation_number)
      : Person(name, 30), _matriculation_number(matriculation_number) {};
  void print() const {
    Person::print();
    std::cout << ", Matrikelnummer " << _matriculation_number << std::endl;
  };
};

int main(int argc, char *argv[]) {
  Student smith = Student("smith", 12345678);
  Lecturer miller = Lecturer("miller", 98);
  smith.print();
  std::cout << "Ausleihdauer: " << smith.get_check_out_duration() << " Tage(e)"
            << std::endl;
  miller.print();
  std::cout << "Ausleihdauer: " << miller.get_check_out_duration() << " Tage(e)"
            << std::endl;
}
