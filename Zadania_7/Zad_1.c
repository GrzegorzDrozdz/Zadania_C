#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

    // ZADANIE 1 część 1

int main() {
    FILE *file;
    char line[100];
    int sum = 0;

    file = fopen("../Zadania_7\\input.txt", "r");

    if (file == NULL) {
        printf("Nie udało się otworzyć pliku.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        char *ptr = line;
        int first_digit = -1, last_digit = -1;

        while (*ptr != '\0') {
            if (isdigit(*ptr)) {
                if (first_digit == -1) {
                    first_digit = *ptr - '0';
                }
                last_digit = *ptr - '0';
            }
            ptr++;
        }

        if (first_digit != -1 && last_digit != -1) {
            int two_digit_number = first_digit * 10 + last_digit;
            sum += two_digit_number;
        }
    }

    fclose(file);

    printf("Suma liczb dwucyfrowych: %d\n", sum);

    return 0;
}
