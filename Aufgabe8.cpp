#include <iostream>

class Point {
private:
  double _x, _y;

public:
  Point(double x = 0.0, double y = 0.0) {
    _x = x;
    _y = y;
  };

  void set_x(double x) { _x = x; }

  void set_y(double y) { _y = y; }

  double get_x() const { return _x; }

  double get_y() const { return _y; }

  void move(double dx, double dy) {
    _x += dx;
    _y += dy;
  };

  void print(bool is_endl = true) const {
    if (is_endl) {
      std::cout << "(" << _x << ", " << _y << ")" << std::endl;
    } else {
      std::cout << "(" << _x << ", " << _y << ")";
    }
  };
};

class Circle {
private:
  Point _centre;
  double _radius;

public:
  Circle(const Point &p = {}, double radius = 1.0) {
    _centre = p;
    _radius = radius;
  };

  void set_centre(const Point &p) { _centre = p; }

  void set_radius(double radius) { _radius = radius; }

  Point get_centre() const { return _centre; }

  double get_radius() const { return _radius; }

  void move(double dx, double dy) {
    double new_x = _centre.get_x() + dx;
    double new_y = _centre.get_y() + dy;
    _centre.set_x(new_x);
    _centre.set_y(new_y);
  };

  void print(bool is_endl = true) const {
    if (is_endl) {
      std::cout << "[(" << _centre.get_x() << ", " << _centre.get_y() << "), "
                << _radius << "]" << std::endl;
    } else {
      std::cout << "[(" << _centre.get_x() << ", " << _centre.get_y() << "), "
                << _radius << "]";
    }
  };
};

int main(int argc, char *argv[]) {
  Point p;
  Circle c(p);
  std::cout << "Ausgabe 1:" << std::endl;
  p.print();
  c.print();
  p.set_x(1.1);
  p.set_y(2.2);
  c.set_centre(p);
  c.set_radius(3.3);
  std::cout << "Ausgabe 2:" << std::endl;
  p.print(false);
  std::cout << " == (" << p.get_x() << ", " << p.get_y() << ")" << std::endl;
  c.print();
  p.move(1.0, 1.0);
  c.move(2.0, 2.0);
  std::cout << "Ausgabe 3:" << std::endl;
  p.print();
  c.print();
  return 0;
}
