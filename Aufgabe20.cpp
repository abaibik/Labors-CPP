#include <iostream>
#include <string>

// Setzen Sie das Dependency Inversion Principle um.

//     Implementieren Sie eine Klasse
//     "AuthenticationResult" mit den konstanten Attributen
//     "_c_is_authenticated" von Typ bool und "_c_username" vom typ string,
//     einem parametrisierten Kontruktor,
//     der die Attribute initialisiert sowie getter -
//         Methoden um die jeweilingen Werte auszulesen.Der
//             Parameter für den Usernamen soll den default -
//         Wert "unauthenticated_user" enthalten.

//         Schreiben Sie ein Interface "IAuthenticationProcedure",
//     das die rein virtuelle Methode "authenticate" mit dem Rückgabewert
//                                    "AuthenticationResult" enthält
//                                        .

//         Schreiben Sie eine Klasse
//         "Client" mit dem Attribut
//         "_authentication_procedure" vom Typ Pointer auf
//         "IAuthenticationProcedure".Die Methode
//         "set_authentication_procedure" nimmt einen Pointer auf
//         "IAuthenticationProcedure" entgegen und setzt das Attribut
//         "_authentication_procedure" entsprechend.Die methode "execute" nimmt
//             keine Parameter entgegen und führt die folgende Logik aus
//     : Es führt zunächst auf dem "_authentication_procedure" -
//         Attribut die Methode
//         "authenticate" aus und weist das Ergebnis einer konstanten vom Typ
//         "AuthenticationResult" zu.Weist das
//         "AuthenticationResult" ein positives Ergebnis aus,
//     so wird auf der Konsole folgendes ausgegeben :

//     Das Programm wird ausgeführt für[user]
//         .War
//             die Authentifizierung nicht erfolgreich so wird folgendes
//             ausgegeben
//     :

//     Das Programm konnte nicht ausgeführt werden.Schreiben
//         Sie drei verschiedene Implementierungen des Interfaces
//     "IAuthenticationProcedure" : "MockAuth",
//     "UsernamePassword" und "Certificate"
//         .

//     Die Klasse "MockAuth" gibt in jedem Fall ein positives
//                "AuthenticationResult" für den Username "Default" zurück
//         .

//     Die Klasse "UsernamePassword" liest
//         nacheinander zunächst den Usernamen und das Passwort ein
//         .Dazu
//             wird der Anwender jeweils über die Konsole zur Eingabe
//             aufgefordert
//     :

//     Username : bzw.

//                Password : Sind Username und Passwort identisch,
//     so gibt die Klasse ein positives
//         "AuthenticationResult" für den entsprechenden Username zurück
//             .Andernfalls wird ein negatives "AuthenticationResult"
//             zurückgegeben
//             .

//         Die Klasse
//         "Certificate" liest den Zertifikatsaussteller von der Konsole ein
//             .Der Anwender wird hierzu folgendermaßen aufgefordert :

//     Zertifikatsaussteller : Ist der Zertifikatsaussteller
//                             "hs-esslingen" so gibt die Klasse ein positives
//                             "AuthenticationResult" zurück mit dem Usernamen
//                             "certificate.owner"
//             .Andernfalls wird ein negatives
//                             "AuthenticationResult" zurückgegeben.

//                             Für die Eingaben :

//     Username : Maier Passwort : Maier

//                                     Zertifikatsaussteller : hs -
//         esslingen erzeugt das Programm die folgende(Ein -) Ausgabe :

//     Authentifizierung über MockAuth Das Programm wird ausgeführt für Default
//         .Authentifizierung über UsernamePassword Username : Maier Password
//     : Maier Das Programm wird ausgeführt für Maier.Authentifizierung über
//       Zertifikat Zertifikatsaussteller
//     : hs -
//         eslingen Das Programm wird ausgeführt für certificate.owner.

class AuthenticationResult {
  const bool _c_is_authenticated;
  const std::string _c_username;

public:
  AuthenticationResult(bool is_authed,
                       const std::string &username = "unauthenticated_user")
      : _c_is_authenticated(is_authed), _c_username(username) {}
  bool is_authenticated() const { return _c_is_authenticated; }
  const std::string &get_username() const { return _c_username; }
};

class IAuthenticationProcedure {
public:
  virtual ~IAuthenticationProcedure() {}
  virtual AuthenticationResult authenticate() = 0;
};

class Client {
  IAuthenticationProcedure *_authentication_procedure;

public:
  void set_authentication_procedure(IAuthenticationProcedure *auth_procedure) {
    _authentication_procedure = auth_procedure;
  }

  void execute() {
    const AuthenticationResult auth_res =
        _authentication_procedure->authenticate();

    if (auth_res.is_authenticated()) {
      std::cout << "Das Programm wird ausgeführt für "
                << auth_res.get_username() << '.' << std::endl;
    } else {
      std::cout << "Das Programm konnte nicht ausgeführt werden." << std::endl;
    }
  }
};

class MockAuthentication : public IAuthenticationProcedure {
public:
  AuthenticationResult authenticate() override {
    return AuthenticationResult(true, "Default");
  };
};

class UsernamePassword : public IAuthenticationProcedure {
private:
  std::string read_param(std::string param_name) {
    std::cout << param_name << ':' << std::endl;
    std::string param;
    std::cin >> param;

    return param;
  }

public:
  AuthenticationResult authenticate() override {
    const std::string username = read_param("Username");
    const std::string password = read_param("Password");

    return AuthenticationResult(username == password, username);
  };
};

class Certificate : public IAuthenticationProcedure {
private:
  std::string read_cert_owner() {
    std::cout << "Zertifikatsaussteller:\n";
    std::string cert_owner;
    std::cin >> cert_owner;

    return cert_owner;
  }

public:
  AuthenticationResult authenticate() override {
    const std::string certificate_owner = read_cert_owner();

    return AuthenticationResult(certificate_owner == "hs-esslingen",
                                "certificate.owner");
  };
};

int main(int argc, char *argv[]) {
  Client client;

  std::cout << "Authentifizierung über das Authentifizierungsverfahren Mock "
               "Authentication"
            << std::endl;
  IAuthenticationProcedure *mock_authentication = new MockAuthentication();
  client.set_authentication_procedure(mock_authentication);
  client.execute();

  std::cout
      << "Authentifizierung über das Authentifizierungsverfahren Username "
         "Password"
      << std::endl;
  IAuthenticationProcedure *username_password = new UsernamePassword();
  client.set_authentication_procedure(username_password);
  client.execute();

  std::cout
      << "Authentifizierung über das Authentifizierungsverfahren Zertifikat"
      << std::endl;
  IAuthenticationProcedure *certificate = new Certificate();
  client.set_authentication_procedure(certificate);
  client.execute();
  return 0;
}
