#include <stdio.h>

int main()
{
    int liczba = 10;
    int *wskaznik = &liczba;
    printf("Wartosc zmiennej: %d\n", liczba);
    printf("Wartosc zmiennej przez wskaznik: %d\n", *wskaznik);
    *wskaznik+=1;
    printf("Wartosc zmiennej przez wskaznik po inkrementacji: %d\n", *wskaznik);
    printf("Wartosc zmiennej: %d\n", liczba);
    return 0;
}
