#include <iostream>

class Date {
private:
  int _day, _month, _year;

public:
  Date(int day = 0, int month = 0, int year = 0) {
    _day = day;
    _month = month;
    _year = year;
  };

  Date operator+(int days) {
    Date result(_day, _month, _year);
    result._day += days;

    while (result._day > 30) {
      result._day -= 30;
      result._month++;
    };

    while (result._month > 12) {
      result._month -= 12;
      result._year++;
    }

    return result;
  };

  friend std::ostream &operator<<(std::ostream &os, const Date &date) {
    os << date._day << '.' << date._month << '.' << date._year;
    return os;
  };
};

int main(int argc, char *argv[]) {
  Date begin_task = Date(26, 10, 2023);
  std::cout << "Die Aufgabe beginnt am " << begin_task << std::endl;
  Date end_task = begin_task + 6;
  std::cout << "Die Aufgabe endet am " << end_task << std::endl;
  Date one_year_and_one_month_later = begin_task + 390;
  std::cout << "Ein Jahr und ein Monat nach Aufgabenbeginn ist der "
            << one_year_and_one_month_later << std::endl;
  Date three_years_and_eleven_months_later = begin_task + 1410;
  std::cout << "Drei Jahre und 11 Monate nach Aufgabenbeginn ist der "
            << three_years_and_eleven_months_later << std::endl;
}
