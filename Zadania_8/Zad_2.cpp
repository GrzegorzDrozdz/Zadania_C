#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>

// Zadanie 7 część 2

using namespace std;

int strToNum(const string& str) {
    if (str == "zero") return 0;
    if (str == "one") return 1;
    if (str == "two") return 2;
    if (str == "three") return 3;
    if (str == "four") return 4;
    if (str == "five") return 5;
    if (str == "six") return 6;
    if (str == "seven") return 7;
    if (str == "eight") return 8;
    if (str == "nine") return 9;
    return -1;
}

int main() {
    ifstream file("../Zadania_7\\input.txt");
    string line;
    int sum = 0;

    if (!file.is_open()) {
        cout << "Nie udało się otworzyć pliku." << endl;
        return 1;
    }

    const string words[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    while (getline(file, line)) {
        int first = -1, last = -1;
        int len = line.length();

        for (int i = 0; i < len; i++) {
            if (isdigit(line[i])) {
                first = line[i] - '0';
                break;
            } else {
                for (int j = 0; j < 10; j++) {
                    if (line.substr(i, words[j].length()) == words[j]) {
                        first = strToNum(words[j]);
                        break;
                    }
                }
                if (first != -1) break;
            }
        }

        for (int i = len - 1; i >= 0; i--) {
            if (isdigit(line[i])) {
                last = line[i] - '0';
                break;
            } else {
                for (int j = 0; j < 10; j++) {
                    if (line.substr(i, words[j].length()) == words[j]) {
                        last = strToNum(words[j]);
                        break;
                    }
                }
                if (last != -1) break;
            }
        }

        if (first != -1 && last != -1) {
            sum += first * 10 + last;
        }
    }

    file.close();

    cout << "Suma liczb dwucyfrowych: " << sum << endl;

    return 0;
}
