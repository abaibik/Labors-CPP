
#include <iostream>
#include <vector>

class Point {
  double _x;
  double _y;

public:
  // Konstruktor mit Parametern
  Point(double x = 0.0, double y = 0.0);
  // Verschiebt einen Punkt
  void move(double dx, double dy);
  // gibt den Punkt auf der Konsole aus
  void print(bool nl = true) const;
};

// Implementierung Konstruktor
Point::Point(double x, double y) : _x(x), _y(y) {}

// Implementierung Methoden
void Point::move(double dx, double dy) {
  _x += dx;
  _y += dy;
}

void Point::print(bool nl) const {
  std::cout << '(' << _x << ", " << _y << ')';
  if (nl) {
    std::cout << std::endl;
  }
}

class Polygonline {
  std::vector<Point> _points;

public:
  // Konstruktor
  Polygonline();
  // Konstruktor mit Parameter
  Polygonline(Point &p);
  // gibt die Elemente des Polygons auf der Konsole aus
  void print(bool nl = true);
  // Hängt einen Punkt hinten an
  Polygonline &add_point(Point p);
  // Hängt einen zusätzlichen Polygon hinten an
  void append_polygonline(Polygonline &pl);
  // Verschiebt den gesamten Polygon
  void move(double dx, double dy);
};

// Implementierung Konstruktor
Polygonline::Polygonline() {}
Polygonline::Polygonline(Point &p) : _points({p}) {}

// Implementierung Methoden

void Polygonline::print(bool nl) {
  std::cout << "|";

  for (std::vector<Point>::size_type i = 0; i < _points.size(); ++i) {
    _points[i].print(false);
    if (i < _points.size() - 1) {
      std::cout << " - ";
    }
  }

  std::cout << "|";

  if (nl) {
    std::cout << std::endl;
  }
}

Polygonline &Polygonline::add_point(Point p) {
  _points.push_back(p);
  return *this;
}

void Polygonline::append_polygonline(Polygonline &pl) {
  _points.insert(_points.end(), pl._points.begin(), pl._points.end());
}

void Polygonline::move(double dx, double dy) {
  for (Point &p : _points) {
    p.move(dx, dy);
  }
}

int main(int argc, char *argv[]) {
  Point p1(1, 1), p2(2, 2), p3(3, 3), p4(4, 4), p5(5, 5);
  Polygonline l1;
  Polygonline l2(p3);
  std::cout << "Ausgabe 1:" << std::endl;
  l1.print();
  l2.print();
  l1.add_point(p1).add_point(p2);
  l2.add_point(p4).add_point(p5);
  std::cout << "Ausgabe 2:" << std::endl;
  l1.print();
  l2.print();
  p2.move(0.5, 0.5);
  std::cout << "Ausgabe 3:" << std::endl;
  p2.print();
  l1.print();
  l2.print();
  l1.append_polygonline(l2);
  std::cout << "Ausgabe 4:" << std::endl;
  l1.print();
  l2.print();
  l1.move(0, 0.5);
  std::cout << "Ausgabe 5:" << std::endl;
  l1.print();
  l2.print();
  return 0;
}
