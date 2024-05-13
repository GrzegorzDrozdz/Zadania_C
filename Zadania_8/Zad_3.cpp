#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
const int MAX_CHARS = 180;

int extract_game_number(const std::string &line) {
    int game_number = 0;
    size_t pos = line.find("Game");
    if (pos != std::string::npos) {
        pos += 5;
        while (isdigit(line[pos])) {
            game_number = game_number * 10 + (line[pos] - '0');
            pos++;
        }
    }
    return game_number;
}

int main() {
    const std::string filename = "../Zadania_7\\input_2.txt";
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Nie można otworzyć pliku." << std::endl;
        exit(EXIT_FAILURE);
    }

    int sum_id = 0;
    int moc_sum = 0;
    std::string line;
    int max_r = 12;
    int max_g = 13;
    int max_b = 14;

    while (std::getline(file, line)) {
        int line_len = line.length();
        int flag = 0;
        int min_r = 0;
        int min_g = 0;
        int min_b = 0;

        int game_number = extract_game_number(line);
        int number;

        for (size_t i = 8; i < line.length(); i++) {
            if (isdigit(line[i])) {
                if (isdigit(line[i + 1])) {
                    number = (line[i] - '0') * 10 + (line[i + 1] - '0');
                    i++;
                } else {
                    number = line[i] - '0';
                }
            }

            if (strncmp(&line[i], "red", 3) == 0) {
                if (number > max_r) {
                    flag = 1;
                }
                if (number > min_r){
                    min_r = number;
                }
            }

            if (strncmp(&line[i], "green", 5) == 0) {
                if (number > max_g) {
                    flag = 1;
                }
                if (number > min_g){
                    min_g = number;
                }
            }

            if (strncmp(&line[i], "blue", 4) == 0) {
                if (number > max_b) {
                    flag = 1;
                }
                if (number > min_b){
                    min_b = number;
                }
            }

        }

        moc_sum += (min_r * min_g * min_b);

        if (flag == 0){
            sum_id += game_number;
        }
    }

    file.close();

    std::cout << "Suma numerow gier, ktore mozna rozegrac: " << sum_id << std::endl;
    std::cout << "Suma mocy zestawow wymaganych do rozegrania gier: " << moc_sum << std::endl;

    return 0;
}
