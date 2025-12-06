#include <array>
#include <iostream>
#include <string>
#include <vector>

// Schreiben Sie die abstrakte Basisklasse 'Meal' mit den Methoden 'add_topping'
// und 'prepare'. Implementieren sie die Klassen Pizza und Burger, sodass das
// vorhandene Programmfragment kompiliert werden und mittels der Zeile *[1]
// folgendes auf der Konsole ausgegeben werden kann:

// Pizza Mista. Pizzaboden, belegt mit:
// - Salami
// - Pilzen
// Pizza Hawaii. Pizzaboden, belegt mit:
// - Schinken
// - Ananas
// Hamburger. Brötchen mit:
// - Hackfleisch
// Cheesburger. Brötchen mit:
// - Hackfleisch
// - Käse

// Nutzen Sie die Vererbung von Instanzvariablen und Instanzmethoden
// entsprechend.

class Meal {
protected:
  std::string _name;
  std::vector<std::string> _toppings;

public:
  Meal(std::string name) : _name(name) {}
  void add_topping(std::string topping) { _toppings.push_back(topping); }
  virtual void prepare() = 0;
};

class Pizza : public Meal {
public:
  Pizza(std::string name) : Meal(name) {}
  void prepare() override {
    std::cout << "Pizza " << _name << ". Pizzaboden, belegt mit:\n";
    for (std::string topping : _toppings) {
      std::cout << "- " << topping << std::endl;
    }
  }
};

class Burger : public Meal {
public:
  Burger(std::string name) : Meal(name) {}
  void prepare() override {
    std::cout << _name << ". Brötchen mit:\n";
    for (std::string topping : _toppings) {
      std::cout << "- " << topping << std::endl;
    }
  }
};

int main(int argc, char *argv[]) {
  Pizza *mista = new Pizza("Mista");
  mista->add_topping("Salami");
  mista->add_topping("Pilzen");
  Meal *hawaii = new Pizza("Hawaii");
  hawaii->add_topping("Schinken");
  hawaii->add_topping("Ananas");
  Burger *hamburger = new Burger("Hamburger");
  hamburger->add_topping("Hackfleisch");
  Meal *cheesburger = new Burger("Cheesburger");
  cheesburger->add_topping("Hackfleisch");
  cheesburger->add_topping("Käse");
  std::array<Meal *, 4> menu = {mista, hawaii, hamburger, cheesburger};
  for (Meal *g : menu) {
    g->prepare(); //*[1]
  }
  return 0;
}
