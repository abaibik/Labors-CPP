#include <iostream>
#include <string>

class A {
public:
  void method_1() { std::cout << "A::method_1()" << std::endl; }
  void method_2(double d) { std::cout << "A::method_2(double)" << std::endl; }
  void method_2(std::string s) {
    std::cout << "A::method_2(string)" << std::endl;
  }
  void method_3(char c) { std::cout << "A::method_3(char)" << std::endl; }
  void method_3(std::string s) {
    std::cout << "A::method_3(string)" << std::endl;
  }
};

class B : public A {
public:
  void method_2(int i) { std::cout << "B::method_2(int)" << std::endl; }
  void method_3(int i) { std::cout << "B::method_3(int)" << std::endl; }
  void method_3(std::string s) {
    std::cout << "B::method_3(string)" << std::endl;
  }
};

int main(int argc, char *argv[]) {
  A a;
  B b;
  std::cout << "a.method_1() ";
  a.method_1();
  // a) keine Fehlermeldung;
  // b) Ausgabe: a.method_1() A::method_1()

  std::cout << "b.method_1() ";
  b.method_1();
  // a) keine Fehlermeldung;
  // b) Ausgabe: b.method_1() A::method_1()

  std::cout << "a.method_2(1.2) ";
  a.method_2(1.2);
  // a) keine Fehlermeldung;
  // b) Ausgabe: a.method_2(1.2) A::method_2(double)

  std::cout << "b.method_2(1.2) ";
  b.method_2(1.2);
  // a) keine Fehlermeldung;
  // b) Ausgabe: b.method_2(1.2) B::method_2(int)
  // c) Methoden 2 der Klasse A wurden verdeckt

  std::cout << "a.method_2(1) ";
  a.method_2(1);
  // a) keine Fehlermeldung;
  // b) Ausgabe: a.method_2(1) A::method_2(double)
  // c) Method A::method_2(string) wurde überlädt

  std::cout << "b.method_2(1) ";
  b.method_2(1);
  // a) keine Fehlermeldung;
  // b) Ausgabe: b.method_2(1) B::method_2(int)
  // c) Methoden 2 der Klasse A wurden verdeckt

  std::cout << "a.method_2('c') ";
  a.method_2('c');
  // a) keine Fehlermeldung;
  // b) Ausgabe: a.method_2('c') A::method_2(double)
  // c) Method A::method_2(string) wurde überlädt

  std::cout << "b.method_2('c') ";
  b.method_2('c');
  // a) keine Fehlermeldung;
  // b) Ausgabe: b.method_2('c') B::method_2(int)
  // c) Methoden 2 der Klasse A wurden verdeckt

  std::cout << "a.method_2(''string'') ";
  a.method_2("string");
  // a) keine Fehlermeldung;
  // b) Ausgabe: a.method_2(''string'') A::method_2(string)
  // c) Method A::method_2(double) wurde überlädt

  std::cout << "b.method_2(''string'') ";
  // b.method_2("string");
  //  a) Fehlermeldung;
  //  b) Ausgabe: b.method_2(''string'')
  //  c) Methoden 2 der Klasse A wurden verdeckt

  std::cout << "a.method_3(1) ";
  a.method_3(1);
  // a) keine Fehlermeldung;
  // b) Ausgabe: a.method_3(1) A::method_3(char)
  // c) Method A::method_3(string) wurde überlädt

  std::cout << "b.method_3(1) ";
  b.method_3(1);
  // a) keine Fehlermeldung;
  // b) Ausgabe: b.method_3(1) B::method_3(int)
  // c) Methoden 3 der Klasse A wurden verdeckt,
  // Method B::method_3(string) wurde überlädt

  std::cout << "a.method_3('c') ";
  a.method_3('c');
  // a) keine Fehlermeldung;
  // b) Ausgabe: a.method_3('c') A::method_3(char)
  // c) Method A::method_3(string) wurde überlädt

  std::cout << "b.method_3('c') ";
  b.method_3('c');
  // a) keine Fehlermeldung;
  // b) Ausgabe: b.method_3('c') B::method_3(int)
  // c) Methoden 3 der Klasse A wurden verdeckt,
  // Method B::method_3(string) wurde überlädt

  std::cout << "a.method_3(''string'') ";
  a.method_3("string");
  // a) keine Fehlermeldung;
  // b) Ausgabe: a.method_3(''string'') A::method_3(string)
  // c) Method A::method_3(char) wurde überlädt

  std::cout << "b.method_3(''string'') ";
  b.method_3("string");
  // a) keine Fehlermeldung;
  // b) Ausgabe: b.method_3(''string'') B::method_3(string)
  // c) Methoden 3 der Klasse A wurden verdeckt,
  // Method B::method_3(int) wurde überlädt

  return 0;
}
