#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

// Zadanie 7 część 1
using namespace std;

int main() {
    ifstream file("../Zadania_7\\input.txt");
    string line;
    int sum = 0;

    if (!file.is_open()) {
        cout << "Nie udało się otworzyć pliku." << endl;
        return 1;
    }

    while (getline(file, line)) {
        int first_digit = -1, last_digit = -1;

        for (char c : line) {
            if (isdigit(c)) {
                if (first_digit == -1) {
                    first_digit = c - '0';
                }
                last_digit = c - '0';
            }
        }

        if (first_digit != -1 && last_digit != -1) {
            int two_digit_number = first_digit * 10 + last_digit;
            sum += two_digit_number;
        }
    }

    file.close();

    cout << "Suma liczb dwucyfrowych: " << sum << endl;

    return 0;
}
