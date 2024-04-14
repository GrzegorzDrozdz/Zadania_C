#include <stdio.h>

int dodawanie(int a, int b) {
    return a + b;
}
int odejmowanie(int a, int b) {
    return a - b;
}
int mnozenie(int a, int b) {
    return a * b;
}


int main() {
    int (*ptr)(int, int);
    int a;
    int b;
    int wynik;
    char operacja;

    printf("Wybierz operacje (+, *, -): ");
    scanf("%c", &operacja);

    switch (operacja) {
        case '+':
            ptr = dodawanie;
            break;
        case '*':
            ptr = mnozenie;
            break;
        case '-':
            ptr = odejmowanie;
            break;
        default:
            printf("Niepoprawna operacja.\n");
            return 1;
    }

    printf("Podaj dwie liczby: ");
    scanf("%d %d", &a, &b);
    wynik = ptr(a, b);
    printf("Wynik: %d\n", wynik);

    return 0;
}
