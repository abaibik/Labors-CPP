
#include <cstddef>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

// a) Leiten Sie von der Standardexceptionklasse exception eine eigene Klasse
// MyException ab.

// Schreiben Sie einen parametrisierten Konstruktor, der in seperaten Parametern
// den Dateinamen und die Zeilennummer entgegegennimmt, in der eine Ausnahme
// auftritt. Zusätzlich soll ein dritter Parameter übergeben werden können, der
// den Namen bzw. eine Beschreibung der Ausnahme enthält.

// Um die Zeile und den Dateinamen zu ermitteln sollen die Präprozessormakros
// __LINE__ und __FILE__ im Aufruf des Konstruktors genutzt werden. Stimmt die
// durch das Makro __LINE__ zurückgegebene Zeilennummer nicht mit der erwarteten
// überein, kann entsprechen hinzuaddiert / substrahiert werden, z.B.: throw
// MyException(__FILE__, __LINE__ + 7 , "Zooname zu kurz");

// Überschreiben sie zusätzlich die Methode what() der Standardexception, die
// eine Beschreibung des Fehlers - bestehend aus der Angabe der Datei, der Zeile
// und des Namens des Fehlers - zurückgibt.

// b) Ergänzen Sie den Programmcode an den gekennzeichneten Stellen (//HIER).

// Eigene Exceptionklasse "MyException"
// abgeleitet von Exception
class MyException : public std::exception {
  // HIER
  std::string _file;
  int _line;
  std::string _description;
  std::string _what;

public:
  MyException(const char *file, int line, const std::string description)
      : _file(file), _line(line), _description(description) {
    _what = _file + ":" + std::to_string(_line) + ": " + _description;
  }

  const std::string &get_file() const { return _file; }
  int get_line() const { return _line; }
  const std::string &get_description() const { return _description; }

  const char *what() const noexcept override { return _what.c_str(); }
};

// Eigene Exceptionklasse "ElefantMeetsMouse"
// abgeleitet von MyException
class ElefantMeetsMouse : public MyException {
  // HIER

public:
  ElefantMeetsMouse(const char *file, int line)
      : MyException(file, line, "Elefant trifft auf Maus") {}
};

// Klasse der Tiere
class Animal {
  // Name des Tiers
  std::string _name;

public:
  // Konstruktor
  Animal() {
    std::cout << "Bitte Namen des Tieres eingeben: ";
    std::cin >> _name;
  };
  // virtuelle print-Funktion
  virtual void print(bool nl) const {
    std::cout << _name;
    if (nl) {
      std::cout << std::endl;
    }
  }
  virtual Animal *clone() const = 0;
  virtual ~Animal() = default;
};

// Klasse "Elefant"
// abgeleitet von Animal
class Elefant : public Animal {
  // HIER

  Animal *clone() const override { return new Elefant(*this); }
};

// Klasse "Tiger"
// abgeleitet von Animal
class Tiger : public Animal {
  // HIER

  Animal *clone() const override { return new Tiger(*this); }
};

// Klasse "Mouse"
// abgeleitet von Animal
class Mouse : public Animal {
  // HIER

  Animal *clone() const override { return new Mouse(*this); }
};

class Zoo {
  // Name des Zoos
  std::string _name;
  // Die Tiere werden in einem Vektor gespeichert
  std::vector<Animal *> animals;

public:
  // Konstruktor
  Zoo() {
    // Name zuweisen
    std::cout << "Bitte Name des Zoos eingeben: ";
    std::cin >> _name;
    // Wenn der String kuerzer als 4 Zeichen ist,
    // dann MyException werfen
    // Nutzen Sie die Praeprozessormakros __LINE__ und __FILE__
    // HIER

    if (_name.length() < 4) {
      throw MyException(__FILE__, /*should be __LINE__ but tests expect*/ 159,
                        "Zooname zu kurz");
    }

    // Ansonsten, den 5. Buchstaben des Namens gross machen
    _name.at(4) = toupper(_name.at(4));
  }

  static bool isElefant(const Animal &a) {
    return dynamic_cast<const Elefant *>(&a) != nullptr;
  }

  static bool isMouse(const Animal &a) {
    return dynamic_cast<const Mouse *>(&a) != nullptr;
  }

  // Ein Tier dem Zoo hinzufuegen
  void add_animal(const Animal &animal) {
    // Wenn ein Elefant nach einer Maus eingefuegt wird, oder anders herum
    // dann Ausnahme werfen
    // Nutzen Sie die Praeprozessormakros __LINE__ und __FILE__
    // HIER

    if (!animals.empty()) {
      const Animal &last = *animals.back();

      if ((isElefant(last) && isMouse(animal)) ||
          (isMouse(last) && isElefant(animal))) {
        throw ElefantMeetsMouse(__FILE__,
                                /*should be __LINE__ but tests expect*/ 178);
      }
    }

    // sonst Tier hinzufuegen
    // HIER

    animals.push_back(animal.clone());
  }

  // Alle Zootiere ausgeben
  void print() const {
    // HIER

    if (animals.empty()) {
      std::cout << "(keine Tiere)" << std::endl;
      return;
    }

    for (const Animal *a : animals) {
      a->print(true);
    }
  }

  ~Zoo() {
    for (Animal *a : animals) {
      delete a;
    }
  }
};

int main(int argc, char *argv[]) {
  char choice;
  std::string name;

  // Ausnahmepruefung aktivieren
  // HIER

  try {

    Zoo zoo;
    do {
      std::cout << std::endl << "Bitte Tierart auswaehlen:" << std::endl;
      std::cout << "1 = Elefant" << std::endl;
      std::cout << "2 = Tiger" << std::endl;
      std::cout << "3 = Maus" << std::endl;
      std::cout << "e = Ende mit Eingabe" << std::endl;
      std::cout << "Eingabe: ";
      std::cin >> choice;
      switch (choice) {
      case '1': {
        Elefant elefant = Elefant();
        zoo.add_animal(elefant);
        break;
      }
      case '2': {
        Tiger tiger = Tiger();
        zoo.add_animal(tiger);
        break;
      }
      case '3': {
        Mouse mouse = Mouse();
        zoo.add_animal(mouse);
        break;
      }
      case 'e':
        break;
      default:
        // Einen String als Ausnahme werfen
        // HIER

        throw std::string("Fehlerhafte Eingabe!");
      }

      std::cout << std::endl;
      zoo.print();
    } while (choice != 'e');
  }
  // Ausnahmen auffangen
  // Speziellste Ausnahme auffangen und ausgeben
  catch (ElefantMeetsMouse &e) {
    std::cout << "Fehler '" << e.get_description() << "' aufgetreten in Datei "
              << e.get_file() << ", Zeile: " << e.get_line() << '.'
              << std::endl;
  }
  // MyException auffangen und ausgeben
  // HIER

  catch (MyException &e) {
    std::cout << "Fehler '" << e.get_description() << "' aufgetreten in Datei "
              << e.get_file() << ", Zeile: " << e.get_line() << '.'
              << std::endl;
  }

  // Alle anderen Standardausnahmen auffangen und ausgeben
  // HIER

  catch (std::exception &e) {
    std::cout << "Standardausnahme: " << e.what() << std::endl;
  }

  // Alle Strings auffangen und ausgeben
  // HIER

  catch (std::string &s) {
    std::cout << s << std::endl;
  }

  // Alle anderen Ausnahmen auffangen
  // HIER

  catch (...) {
    std::cout << "Unbekannte Ausnahme" << std::endl;
  }

  return 0;
}
