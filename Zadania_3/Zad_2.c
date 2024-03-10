#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **alokuj_macierz(int ilosc_wierszy, int ilosc_kolumn) {
    int **macierz = malloc(ilosc_wierszy * sizeof(int *));
    for (int i = 0; i < ilosc_wierszy; i++) {
        macierz[i] = calloc(ilosc_kolumn, sizeof(int));
    }
    return macierz;
}

void wypelnij_macierz(int **macierz, int ilosc_wierszy, int ilosc_kolumn) {
    srand(time(NULL));
    for (int i = 0; i < ilosc_wierszy; i++) {
        for (int j = 0; j < ilosc_kolumn; j++) {
            macierz[i][j] = rand() % 100;
        }
    }
}

void wyswietl_macierz(int **macierz, int ilosc_wierszy, int ilosc_kolumn) {
    for (int i = 0; i < ilosc_wierszy; i++) {
        for (int j = 0; j < ilosc_kolumn; j++) {
            printf("%3d ", macierz[i][j]);
        }
        printf("\n");
    }
}

void zwolnijPamiec(int **macierz, int ilosc_wierszy) {
    for (int i = 0; i < ilosc_wierszy; i++) {
        free(macierz[i]);
    }
    free(macierz);
}

int main() {
    int ilosc_wierszy, ilosc_kolumn;
    printf("Podaj ilosc wierszy: ");
    scanf("%d", &ilosc_wierszy);
    printf("Podaj ilosc kolumn: ");
    scanf("%d", &ilosc_kolumn);

    int **macierz = alokuj_macierz(ilosc_wierszy, ilosc_kolumn);
    if (macierz == NULL)
    {
        printf("Nie udalo sie zaalokowac pamieci dla macierzy");
        return 1;
    }

    wypelnij_macierz(macierz, ilosc_wierszy, ilosc_kolumn);
    wyswietl_macierz(macierz, ilosc_wierszy, ilosc_kolumn);
    zwolnijPamiec(macierz, ilosc_wierszy);

    return 0;
}
