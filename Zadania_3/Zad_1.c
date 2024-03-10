#include <stdio.h>
#include <stdlib.h>

int **stworzTrojkatPascala(int n) {
    int **trojkat = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        trojkat[i] = calloc(i + 1, sizeof(int));
    }

    trojkat[0][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                trojkat[i][j] = 1;
            } else {
                trojkat[i][j] = trojkat[i - 1][j - 1] + trojkat[i - 1][j];
            }
        }
    }

    return trojkat;
}

void wyswietlTrojkat(int **trojkat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf(" %3d ", trojkat[i][j]);
        }
        printf("\n");
    }
}

void zwolnijPamiec(int **trojkat, int n) {
    for (int i = 0; i < n; i++) {
        free(trojkat[i]);
    }
    free(trojkat);
}

int main() {
    int n;
    printf("Podaj wysokosc trojkata Pascala: ");
    scanf("%d", &n);

    int **trojkat = stworzTrojkatPascala(n);
    wyswietlTrojkat(trojkat, n);
    zwolnijPamiec(trojkat, n);

    return 0;
}
