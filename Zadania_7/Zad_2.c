#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// ZADANIE 1 część 2

int strToNum(char *str) {
    if (strcmp(str, "zero") == 0) return 0;
    if (strcmp(str, "one") == 0) return 1;
    if (strcmp(str, "two") == 0) return 2;
    if (strcmp(str, "three") == 0) return 3;
    if (strcmp(str, "four") == 0) return 4;
    if (strcmp(str, "five") == 0) return 5;
    if (strcmp(str, "six") == 0) return 6;
    if (strcmp(str, "seven") == 0) return 7;
    if (strcmp(str, "eight") == 0) return 8;
    if (strcmp(str, "nine") == 0) return 9;
    return -1;
}

int main() {
    FILE *file;
    char line[100];
    int sum = 0;

    file = fopen("../Zadania_7\\input.txt", "r");

    if (file == NULL) {
        printf("Nie udało się otworzyć pliku.\n");
        return 1;
    }

    char *words[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    while (fgets(line, sizeof(line), file)) {
        int first = -1, last = -1;
        int len = strlen(line);

        for (int i = 0; i < len; i++) {
            if (isdigit(line[i])) {
                first = line[i] - '0';
                break;
            } else {
                for (int j = 0; j < 10; j++) {
                    if (strncmp(&line[i], words[j], strlen(words[j])) == 0) {
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
                    if (strncmp(&line[i], words[j], strlen(words[j])) == 0) {
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

    fclose(file);

    printf("Suma liczb dwucyfrowych: %d\n", sum);

    return 0;
}
