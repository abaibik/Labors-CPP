
#include <iostream>

class Point
{
  private:
    double x_;
    double y_;

  public:
    Point() : x_(0.0), y_(0.0)
    {
    }

    void set_x(double x)
    {
        x_ = x;
    }

    void set_y(double y)
    {
        y_ = y;
    }

    double get_x()
    {
        return x_;
    }

    double get_y()
    {
        return y_;
    }

    void print()
    {
        std::cout << "print-Methode:" << std::endl;
        std::cout << "X = " << x_ << std::endl;
        std::cout << "Y = " << y_ << std::endl;
    }
};

int main(int argc, char *argv[])
{
    Point p;
    p.set_x(1);
    p.set_y(10.5);
    p.print();
    p.set_x(5);
    std::cout << "X ohne print(): " << p.get_x() << std::endl;
    std::cout << "Y ohne print(): " << p.get_y() << std::endl;
    return 0;
}
