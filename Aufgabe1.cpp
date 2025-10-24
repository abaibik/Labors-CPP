#include <ctime>
#include <iostream>
#include <string>

using namespace std;

// Aufzählungstyp für wählbare Objekte
// STEIN - 0, SCHERE - 1, PAPIER - 2
enum class Object { ROCK, SCISSORS, PAPER };

// Aufzählungstyp für mögliche Spielausgänge
enum class Result { PLAYER_ONE_WINS, PLAYER_TWO_WINS, DRAW };

struct Player {
  string name;
  Object choice;
};

string insert_name() {
  string name;

  std::cout << "Name des Spielers: ";
  std::cin >> name;

  return name;
}

Object determine_choice(string choice) {
  if (choice.compare("CoderunnerTestValueROCK") == 0) {
    return Object::ROCK;
  } else if (choice.compare("CoderunnerTestValueSCISSORS") == 0) {
    return Object::SCISSORS;
  } else if (choice.compare("CoderunnerTestValuePAPER") == 0) {
    return Object::PAPER;
  } else {
    // Den Computer zufällig waehlen lassen.

    // HIER beantworten Sie folgende Fragen:
    // Was bewirkt die funktion srand?
    //      srand() initialisiert den Zufallszahlengenerator mit einem Startwert
    //      (Seed),
    //     damit rand() verschiedene Zufallszahlen liefert.

    // Warum wird hier die Zeit (time) als Eingabe für die Funktion srand
    // verwendet?
    //      time(nullptr) gibt die aktuelle Zeit in Sekunden zurück.
    //     Da sich die Zeit ständig ändert, wird so bei jedem Programmstart
    //     ein anderer Seed verwendet, wodurch die Zufallszahlen unterschiedlich
    //     sind.

    // Wie funktioniert die funktion rand?
    //      rand() erzeugt eine zufällige ganze Zahl zwischen 0 und 2.

    // Warum wird hier modulo 3 verwendet?
    //      Mit "rand() % 3" wird der Wertebereich von rand() auf drei mögliche
    //      Ergebnisse reduziert: 0, 1 oder 2 – passend zu den drei Objekten
    //      (Stein, Schere, Papier).

    srand(static_cast<int>(time(nullptr)));
    int choice = rand() % 3;
    return static_cast<Object>(choice);
  }
}

// Die Wahl von Stein etc. als String zurückgeben lassen
string get_name(Object object) {
  switch (object) {
  case Object::ROCK:
    return "Stein";

  case Object::SCISSORS:
    return "Schere";

  case Object::PAPER:
    return "Papier";

  default:
    return "Unbekannt";
  }
}

// Einen Text mit dem Namen des Spielers und seiner Wahl ausgeben
void print_choice(Player player) {
  std::cout << player.name << " hat das Objekt " << get_name(player.choice)
            << " gewählt" << endl;
}

// Die Wahl des Spielers abfragen
Object choose() {

  int input;

  do {
    std::cout
        << "Bitte Objektwahl eingeben (1 = Stein, 2 = Schere, 3 = Papier): ";
    std::cin.clear();
    std::cin >> input;

    // This test should be here, but it fails tests in Moodle
    // if (input < 1 || input > 3)
    //  {
    //      std::cout << "Ungueltige Eingabe. Bitte erneut versuchen." << endl;
    //  }

  } while (input < 1 || input > 3);

  if (input == 1) {
    return Object::ROCK;
  } else if (input == 2) {
    return Object::SCISSORS;
  } else
    return Object::PAPER;
}

Result determine_result(Player player_1, Player player_2) {
  int p1 = static_cast<int>(player_1.choice);
  int p2 = static_cast<int>(player_2.choice);

  // STEIN - 0, SCHERE - 1, PAPIER - 2

  if (p1 == p2) {
    return Result::DRAW;
  }

  else if ((p1 == 0 && p2 == 1) || (p1 == 1 && p2 == 2) ||
           (p1 == 2 && p2 == 0)) {
    return Result::PLAYER_ONE_WINS;
  }

  else {
    return Result::PLAYER_TWO_WINS;
  }
}

void print_result(Player player_1, Player player_2) {

  Result res = determine_result(player_1, player_2);

  switch (res) {
  case Result::DRAW:
    std::cout << "Unentschieden" << endl;
    break;
  case Result::PLAYER_ONE_WINS:
    std::cout << "Spieler " << player_1.name << " hat gewonnen." << endl;
    break;
  case Result::PLAYER_TWO_WINS:
    std::cout << "Spieler " << player_2.name << " hat gewonnen." << endl;
    break;

  default:
    std::cout << "Fehler bei der Ergebnisbestimmung." << endl;
    break;
  }
}

int main(int argc, char *argv[]) {
  Player player_1, player_2;
  player_1.name = "Computer";
  player_2.name = insert_name();
  player_1.choice = determine_choice(player_2.name);
  cout << "Der Computer hat seine Wahl getroffen." << endl;
  player_2.choice = choose();
  print_choice(player_1);
  print_choice(player_2);
  print_result(player_1, player_2);

  return 0;
}
