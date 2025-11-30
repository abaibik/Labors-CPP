
#include <iostream>
#include <string>

void p(std::string s, bool nl = true) {
  std::cout << s << " ";
  if (nl) {
    std::cout << std::endl;
  }
}

class A {
public:
  void method_1() { p("A::method_1()"); }
  virtual void method_2() { p("A::method_2()"); }
  void method_3() { p("A::method_3()"); }
  void method_4() {
    p("A::method_4()", false);
    method_2();
  }
};

class B : public A {
public:
  void method_1() { p("B::method_1()"); }
  void method_2() { p("B::method_2()"); }
  void method_3() { p("B::method_3()"); }
  virtual void method_4() {
    p("B::method_4()", false);
    method_2();
  }
};

class C : public B {
public:
  void method_1() { p("C::method_1()"); }
  void method_2() { p("C::method_2()"); }
  virtual void method_3() { p("C::method_3()"); }
  void method_4() {
    p("C::method_4()", false);
    method_2();
  }
};

class D : public C {
public:
  void method_1() { p("D::method_1()"); }
  void method_2() { p("D::method_2()"); }
  void method_3() { p("D::method_3()"); }
};

int main(int argc, char *argv[]) {
  D d;
  A *p_a = &d;
  B *p_b = &d;
  C *p_c = &d;
  p_a->method_1();
  p_b->method_1();
  p_c->method_1();

  p_a->method_2(); // D::method_2() is requested, A::method_2() was instead.
                   // Decision: make method 2 in A virtual
  p_b->method_2();
  p_c->method_2();

  p_a->method_3();
  p_b->method_3();
  p_c->method_3(); // D::method_3() is requested, C::method_3() was instead.
                   // Decision: make method 3 in C virtual

  p_a->method_4();
  p_b->method_4(); // C::method_4() D::method_2() is requested, B::method_4()
                   // D::method_2() was instead. Decision: make method 4 in B
                   // virtual

  p_c->method_4();
}
