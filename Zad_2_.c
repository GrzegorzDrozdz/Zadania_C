#include <stdio.h>

void Dwukrotnosc(float *ptr)
{
    *ptr *= 2;
}

int main() {
    float x = 87.776;
    float *ptr = &x;
    printf("Wartosc zmiennej przed modyfikacja: %.2f\n", x);
    printf("Wartosc zmiennej przez wskaznik przed modyfikacja: %.2f\n", x);
    Dwukrotnosc(ptr);
    printf("Wartosc zmiennej po modyfikacji: %.2f\n", x);
    printf("Wartosc zmiennej przez wskaznik po modyfikacji: %.2f\n", x);
    return 0;
}
