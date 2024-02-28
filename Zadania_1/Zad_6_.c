//
// Created by grzeg on 28.02.2024.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROUNDS 10

char *numerNaRuch(int numer) {
    switch (numer) {
        case 0: return "Papier";
        case 1: return "Kamien";
        case 2: return "Nozyce";
        default: return "Nieznany ruch";
    }
}


int Zadanie6(){
    char *ruchy[] = {"Papier", "Kamien", "Nozyce"};
    int gracz, ruchKomputera;
    int wygrane = 0, przegrane = 0, remis = 0;
    int historiascore[MAX_ROUNDS], historiagracz[MAX_ROUNDS], historiakomputer[MAX_ROUNDS];
    int liczbaRund = 0;

    printf("Zagraj w Papier, Kamien, Nozyce!\n Ile rund chcesz rozegrac: ");
    scanf("%d", &liczbaRund);
    srand(time(NULL));

    for (int round = 0; round < liczbaRund; round++)
    {
        printf("\nRunda %d\nWybierz ruch (0 - Papier, 1 - Kamien, 2 - Nozyce): ", round + 1);
        scanf("%d", &gracz);

        ruchKomputera = rand() % 3;

        printf("Komputer wybral: %s\n", ruchy[ruchKomputera]);

        if (gracz == ruchKomputera)
        {
            historiascore[round] = 0;
        }
        else if ((gracz == 0 && ruchKomputera == 1) || (gracz == 1 && ruchKomputera == 2) || (gracz == 2 && ruchKomputera == 0))
        {
            historiascore[round] = 1;
        } else
        {
            historiascore[round] = -1;
        }

        historiagracz[round] = gracz;
        historiakomputer[round] = ruchKomputera;

        if (historiascore[round] == 0)
        {
            remis++;
        }
        else if (historiascore[round] == 1)
        {
            wygrane++;
        }
        else
        {
            przegrane++;
        }

        if (historiascore[round] == 0)
        {
            printf("remis!\n");
        }
        else if (historiascore[round] == 1)
        {
            printf("wygrales!\n");
        }
        else
        {
            printf("przegrales!\n");
        }
    }

    printf("Wyniki po %d rundach:\nGracz: %d zwyciestw, Komputer: %d zwyciestw, Remisy: %d\n", liczbaRund, wygrane, przegrane, remis);
    printf("\nCzy chcesz zobaczyc historie rund? (Tak/Nie): ");
    char choice[10];
    scanf("%s",choice);

    if (strcmp(choice, "Tak") == 0 || strcmp(choice, "tak") == 0)
    {
        printf("\nHistoria rund:\n");
        for (int i = 0; i < liczbaRund; i++) {
            printf("Runda %d: Gracz: %s, Komputer: %s, Wynik: %s\n", i + 1, numerNaRuch(historiagracz[i]), numerNaRuch(historiakomputer[i]), (historiascore[i] == 0) ? "Remis" : (historiascore[i] == 1) ? "Gracz wygrywa" : "Komputer wygrywa");
        }
    }

    return 0;
}
int main()
{
    Zadanie6();
}