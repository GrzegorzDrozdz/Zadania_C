#include <stdio.h>

int main() {
    int tablica[10];

    for (int i = 0; i < 10; i++) {
        tablica[i] = i;
    }

    int *ptr = tablica;
    printf("Wartosc \t\t Adres\n");
    for (int i = 0; i < 10; i++) {
        printf("%d \t\t %p\n", *ptr, ptr);
        ptr++;
    }

    return 0;
}
