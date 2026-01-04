#include <exception>
#include <iostream>
#include <vector>

// Themen
//     : Interfaces,
//       Dependency Inversion Principle,
//       Composite Pattern

//               Ihre Aufgabe
//     : Der Preis für ein einzelnes Produkt soll auf die gleiche Art und Weise
//           abgefragt werden können wie für ein Paket in dem Produkte und /
//       oder weitere Pakete enthalten sein können,
//       die wiederum Produkte und /
//           oder weitere Pakete enthalten
//               können.Nutzen Sie hierzu das Composite Pattern.Implementieren
//               sie
//                   das Interface IComponent sowie die Klassen Product und Box

class IComponent {
public:
  virtual int get_price() = 0;
  virtual void add(IComponent *component) = 0;
};

class Product : public IComponent {
private:
  int _price;

public:
  Product(int price) : _price(price) {}
  int get_price() override { return _price; }
  void add(IComponent *component) override { throw std::exception(); }
};

class Box : public IComponent {
private:
  std::vector<IComponent *> _components;

public:
  int get_price() override {
    int result = 0;
    for (IComponent *component : _components) {
      result += component->get_price();
    }

    return result;
  }

  void add(IComponent *component) override { _components.push_back(component); }
};

void calculate_price(IComponent *component) {
  std::cout << "Preis: " << component->get_price() << std::endl;
}

int main(int argc, char *argv[]) {

  std::cout << "Preisermittlung für ein einfaches Produkt: " << std::endl;
  IComponent *product = new Product(10);
  calculate_price(product);
  std::cout << std::endl;

  std::cout << "Preisermittlung für eine verschachtelte Box: " << std::endl;
  IComponent *outer_box = new Box;
  IComponent *inner_box_1 = new Box;
  IComponent *product_1 = new Product(10);
  IComponent *product_2 = new Product(5);
  IComponent *product_3 = new Product(4);
  inner_box_1->add(product_1);
  inner_box_1->add(product_2);
  IComponent *inner_box_2 = new Box;
  inner_box_2->add(product_3);
  outer_box->add(inner_box_1);
  outer_box->add(inner_box_2);
  calculate_price(outer_box);
  std::cout << std::endl;

  std::cout << "Preisermittlung für eine erweiterte verschachtelte Box: "
            << std::endl;
  IComponent *product_4 = new Product(7);
  inner_box_2->add(product_4);
  calculate_price(outer_box);
  std::cout << std::endl;

  return 0;
}
