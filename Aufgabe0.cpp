#include <iostream>

int main(int argc, char *argv[])
{
    int quantity;
    std::cout << "Anzahl eingeben:\n";
    std::cin >> quantity;

    int numbers[10];
    int sum = 0;

    for (int i = 0; i < quantity; i++)
    {
        std::cout << "Zahl eingeben:\n";
        std::cin >> numbers[i];
        sum += numbers[i];
    }

    for (int i = 0; i < quantity; i++)
    {
        std::cout << "Zahl[" << i << "]: " << numbers[i] << "\n";
    }

    float mean = static_cast<float>(sum) / quantity;

    std::cout << "Durchschnitt: " << mean << "\n";

    return 0;
}