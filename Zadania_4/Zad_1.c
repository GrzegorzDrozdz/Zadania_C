#include <stdio.h>

unsigned long long Silnia(unsigned long long n) {
    if (n == 0)
        return 1;
    else
        return n * Silnia(n - 1);
}

int main() {
    unsigned long long n;

    printf("Podaj dodatnia liczbe calkowita: ");
    scanf("%llu", &n);

    if (n <= 0) {
        printf("Blad\n");
    } else {
        printf("%llu! = %llu\n", n, Silnia(n));
    }

    return 0;
}
