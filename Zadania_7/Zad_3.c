#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ZADANIE 2

#define MAX_CHARS 180

typedef struct {
    int red;
    int green;
    int blue;
} Game;

int extract_game_number(char line[]) {
    int game_number = 0;
    sscanf(line, "Game %d:", &game_number);
    return game_number;
}

int main(){
    const char *filename = "../Zadania_7\\input_2.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Nie można otworzyć pliku.\n");
        exit(EXIT_FAILURE);
    }

    int sum_id = 0;
    int moc_sum = 0;
    char line[MAX_CHARS];
    int max_red = 12;
    int max_green = 13;
    int max_blue = 14;

    while (fgets(line, sizeof(line), file)) {
        Game game = {0, 0, 0};
        char *token = strtok(line, ":;");
        token = strtok(NULL, ":;");

        while (token != NULL) {
            int count;
            char color[10];
            sscanf(token, "%d %s", &count, color);
            if (strcmp(color, "red") == 0) {
                game.red += count;
            } else if (strcmp(color, "green") == 0) {
                game.green += count;
            } else if (strcmp(color, "blue") == 0) {
                game.blue += count;
            }
            token = strtok(NULL, ":;");
        }

        if (game.red <= max_red && game.green <= max_green && game.blue <= max_blue) {
            int game_number = extract_game_number(line);
            sum_id += game_number;
            moc_sum += game.red + game.green + game.blue;
        }
    }

    fclose(file);

    printf("Suma numerow gier, ktore mozna rozegrac: %d\n", sum_id);
    printf("Suma mocy zestawow wymaganych do rozegrania gier: %d\n", moc_sum);

    return 0;
}
