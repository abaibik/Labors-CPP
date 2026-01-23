#include <exception>
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <string>

// Hier Exception implementieren

class OutOfStockException : public std::exception {
  int _available, _requested;
  std::string _product_name;
  std::string _message;

public:
  OutOfStockException(int available, int requested,
                      const std::string &product_name)
      : _available(available), _requested(requested),
        _product_name(product_name) {
    std::stringstream ss;
    ss << "Es sind " << _available << " Artikel vom Typ " << _product_name
       << " verfügbar. Es können nicht " << _requested
       << " Artikel verkauft werden.";
    _message = ss.str();
  }
  const char *what() const noexcept override { return _message.c_str(); }
};

// Hier Interface implementieren

class ISubscriber {
public:
  virtual ~ISubscriber() = default;
  virtual void update(const std::string &message) = 0;
};

// Hier Klassen Customer und GoldCustomer implementieren

class Customer : public ISubscriber {
private:
  static int _id_generator;
  int _id;

public:
  Customer() : _id(++_id_generator) {}
  void update(const std::string &message) override {
    std::cout << "Customer " << _id << ": neue Nachricht verfügbar --> "
              << message << std::endl;
  }
};

class GoldCustomer : public ISubscriber {
private:
  static int _id_generator;
  int _id;

public:
  GoldCustomer() : _id(++_id_generator) {}
  void update(const std::string &message) override {
    std::cout << "GoldCustomer " << _id << ": neue Nachricht verfügbar --> "
              << message << std::endl;
  }
};

class Store {
  // Hier Methoden implementieren

private:
  std::list<ISubscriber *> _subscribers;
  std::map<std::string, unsigned int> _product_availability{{"iPhone", 0},
                                                            {"Galaxy", 5}};

public:
  void subscribe(ISubscriber *subscriber) {
    _subscribers.push_back(subscriber);
  }

  void unsubscribe(ISubscriber *subscriber) { _subscribers.remove(subscriber); }

  void notify_subscribers(const std::string &message) {
    for (auto *s : _subscribers) {
      if (s)
        s->update(message);
    }
  }

  void deliver_products(std::string product_name, int quantity) {
    auto iterator = _product_availability.find(product_name);

    int available;
    if (iterator == _product_availability.end()) {
      available = 0;
      _product_availability.insert({product_name, quantity});
    } else {
      available = iterator->second;
      iterator->second += quantity;
    }

    int new_available = available + quantity;

    std::cout << "Vorrätige Artikel vom Typ " << product_name << ": "
              << available << std::endl
              << "Ausgelieferte Artikel vom Typ " << product_name << ": "
              << quantity << std::endl
              << "Neuer Bestand: " << new_available << std::endl;

    if (available == 0 && new_available > 0) {
      notify_subscribers("Neue Artikel vom Typ " + product_name +
                         " verfügbar.");
    }
  }
  void sell_products(std::string product_name, int quantity) {
    auto iterator = _product_availability.find(product_name);

    if (iterator == _product_availability.end()) {
      throw OutOfStockException(0, quantity, product_name);
    }

    int available = static_cast<int>(iterator->second);

    if (quantity > available) {
      throw OutOfStockException(available, quantity, product_name);
    }

    std::cout << "Vorrätige Artikel vom Typ " << product_name << ": "
              << available << std::endl
              << "Verkaufte Artikel vom Typ " << product_name << ": "
              << quantity << std::endl;

    iterator->second = static_cast<unsigned int>(available - quantity);

    std::cout << "Neuer Bestand: " << iterator->second << std::endl;

    if (iterator->second == 0) {
      notify_subscribers("Artikel vom Typ " + product_name +
                         " nicht mehr verfügbar");
    }
  }
};

int Customer::_id_generator = 100;
int GoldCustomer::_id_generator = 0;

void manage_store() {
  try {
    Store *store = new Store;
    ISubscriber *customer_1 = new Customer();
    store->subscribe(customer_1);
    ISubscriber *customer_2 = new GoldCustomer();
    store->subscribe(customer_2);
    ISubscriber *customer_3 = new GoldCustomer();
    store->subscribe(customer_3);
    store->deliver_products("iPhone", 5);
    store->unsubscribe(customer_3);
    store->sell_products("iPhone", 3);
    ISubscriber *customer_4 = new Customer();
    store->subscribe(customer_4);
    store->deliver_products("iPhone", 5);
    store->sell_products("iPhone", 7);
    store->unsubscribe(customer_1);
    ISubscriber *customer_5 = new GoldCustomer();
    store->subscribe(customer_5);
    store->deliver_products("iPhone", 15);
    store->sell_products("Galaxy", 8);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  } catch (...) {
    std::cout << "Ein unbekannter Fehler ist aufgetreten." << std::endl;
  }
}

int main(int argc, char *argv[]) {
  manage_store();
  return 0;
}
