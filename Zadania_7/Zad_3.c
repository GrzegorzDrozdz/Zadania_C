#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// ZADANIE 2 CZĘŚĆ 1 i 2
#define MAX_CHARS 500

int gameNum(char line[]) {
    int i = 0;
    int num = 0;
    int game_found = 0;

    while (line[i] != '\0') {
        if (line[i] == 'G' && line[i + 1] == 'a' && line[i + 2] == 'm' && line[i + 3] == 'e') {
            game_found = 1;
            break;
        }
        i++;
    }

    if (game_found) {
        i += 5;
        while (isdigit(line[i])) {
            num = num * 10 + (line[i] - '0');
            i++;
        }
    }

    return num;
}

void process_line(char line[], int *game_number_sum, int *power_sum, int max_red, int max_green, int max_blue) {
    int len = strlen(line);
    int flag = 0;
    int min_red = 0;
    int min_green = 0;
    int min_blue = 0;

    if (len <= 1)
        return;

    int game_number = gameNum(line);
    int number;


    for (int i = 8; i < len; i++) {

        if (isdigit(line[i])) {

            if (isdigit(line[i + 1])) {
                number = (line[i] - '0') * 10 + (line[i + 1] - '0');
                i++;
            } else {
                number = line[i] - '0';
            }
        }

        if (strncmp(&line[i], "red", 3) == 0) {
            if (number > max_red) {
                flag = 1;
            }
            if (number > min_red){
                min_red = number;
            }
        }

        if (strncmp(&line[i], "green", 5) == 0) {
            if (number > max_green) {
                flag = 1;
            }
            if (number > min_green){
                min_green = number;
            }
        }

        if (strncmp(&line[i], "blue", 4) == 0) {
            if (number > max_blue) {
                flag = 1;
            }
            if (number > min_blue){
                min_blue = number;
            }
        }
    }

    *power_sum += (min_red * min_green * min_blue);
    if (flag == 0){
        *game_number_sum += game_number;
    }
}

int main(){
    const char *filename = "../Zadania_7\\input_2.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Nie można otworzyć pliku.\n");
        exit(EXIT_FAILURE);
    }

    int sum_games = 0;
    int sum_power = 0;
    char line[MAX_CHARS];
    int max_red = 12;
    int max_green = 13;
    int max_blue = 14;

    while (fgets(line, sizeof(line), file)) {
        process_line(line, &sum_games, &sum_power, max_red, max_green, max_blue);
    }

    fclose(file);

    printf("Suma numerow gier, ktore mozna rozegrac: %d\n", sum_games);
    printf("Suma mocy zestawow wymaganych do rozegrania gier: %d\n", sum_power);

    return 0;
}
