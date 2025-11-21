#include <array>
#include <cstddef>
#include <iostream>

const unsigned int length = 10;

// hier die Funktion 'sort' implementieren
template <typename T, unsigned int S>
std::array<T, S> sort(std::array<T, S> arr) {
  for (int i = 0; i < length - 1; i++) {
    for (int j = 0; j < length - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }
  return arr;
}

int main(int argc, char *argv[]) {
  std::array<int, length> int_container = {10, 2, 7, 5, 8, 3, 4, 1, 9, 6};
  std::array<int, length> sorted_int_container = sort(int_container);

  for (size_t i = 0; i < sorted_int_container.size(); i++) {
    std::cout << i << ": " << sorted_int_container[i] << std::endl;
  }

  std::array<char, length> char_container = {'j', 'm', 'e', 't', 'k',
                                             'o', 'p', 's', 'a', 'f'};
  std::array<char, length> sorted_char_container = sort(char_container);

  for (size_t i = 0; i < sorted_char_container.size(); i++) {
    std::cout << i << ": " << sorted_char_container[i] << std::endl;
  }

  std::array<std::string, length> string_container = {
      "Im",   "Sommer", "ist", "es",     "meistens",
      "heiß", "und",    "es",  "regnet", "wenig."};
  std::array<std::string, length> sorted_string_container =
      sort(string_container);

  for (size_t i = 0; i < sorted_string_container.size(); i++) {
    std::cout << i << ": " << sorted_string_container[i] << std::endl;
  }
}
