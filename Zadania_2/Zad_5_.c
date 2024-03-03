#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct
{
    char imie[100];
    char nazwisko[100];
    char numer_telefonu[14];
} Contact;

Contact ksiazka_adresowa[MAX_CONTACTS] = {
        {"Jan", "Kowalski", "111111111"},
        {"Marek", "Nowak", "222222222"},
        {"Piotr", "Kowal", "333333333"},
        {"Ola", "Dabrowska", "444444444"},
        {"Robert", "Lewandowski", "555555555"}
};
int liczba_kontaktow = 5;

void dodaj(Contact *ksiazka_adresowa, int *liczba_kontaktow)
{
    if (*liczba_kontaktow < MAX_CONTACTS)
    {
        Contact *nowy_kontakt = &ksiazka_adresowa[*liczba_kontaktow];
        printf("Podaj imie: ");
        scanf("%s", nowy_kontakt->imie);

        printf("Podaj nazwisko: ");
        scanf("%s", nowy_kontakt->nazwisko);

        printf("Podaj nr tel: ");
        scanf("%s", nowy_kontakt->numer_telefonu);

        (*liczba_kontaktow)++;

        printf("Kontakt dodany.\n");
    }
    else
    {
        printf("Osiagnieto maksymalna liczbe kontaktow.\n");
    }
}

void znajdzNazwisko(Contact *ksiazka_adresowa, int liczba_kontaktow)
{
    char nazwisko[100];
    printf("Podaj nazwisko kontaktu do wyszukania: ");
    scanf("%s", nazwisko);

    int znaleziono = 0;
    for (int i = 0; i < liczba_kontaktow; i++)
    {
        if (strcmp(ksiazka_adresowa[i].nazwisko, nazwisko) == 0)
        {
            printf("Znaleziono kontakt:\n");
            printf("Imie: %s\n", ksiazka_adresowa[i].imie);
            printf("Nazwisko: %s\n", ksiazka_adresowa[i].nazwisko);
            printf("Nr tel: %s\n", ksiazka_adresowa[i].numer_telefonu);
            znaleziono = 1;
        }
    }
    if (znaleziono == 0)
    {
        printf("Nie znaleziono.\n");
    }
}

void usunPoNazwisku(Contact *ksiazka_adresowa, int *liczba_kontaktow)
{
    char nazwisko[100];
    printf("Podaj nazwisko kontaktu do usuniecia: ");
    scanf("%s", nazwisko);

    int znaleziono = 0;
    for (int i = 0; i < *liczba_kontaktow; i++)
    {
        if (strcmp(ksiazka_adresowa[i].nazwisko, nazwisko) == 0)
        {
            for (int j = i; j < *liczba_kontaktow - 1; j++)
            {
                ksiazka_adresowa[j] = ksiazka_adresowa[j + 1];
            }
            (*liczba_kontaktow)--;
            printf("Kontakt o nazwisku %s usunieto.\n", nazwisko);
            znaleziono = 1;
            break;
        }
    }
    if (znaleziono == 0)
    {
        printf("Nie znaleziono.\n");
    }
}

void wypiszKontakty(Contact *ksiazka_adresowa, int liczba_kontaktow)
{
    printf("Ksiazka adresowa:\n");
    for (int i = 0; i < liczba_kontaktow; i++)
    {
        printf("Kontakt %d:\n", i + 1);
        printf("Imie: %s\n", ksiazka_adresowa[i].imie);
        printf("Nazwisko: %s\n", ksiazka_adresowa[i].nazwisko);
        printf("Nr tel: %s\n", ksiazka_adresowa[i].numer_telefonu);
    }
}

int main()
{
    int opcja;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Dodaj kontakt\n");
        printf("2. Znajdz kontakt po nazwisku\n");
        printf("3. Usun kontakt po nazwisku\n");
        printf("4. Wyswietl wszystkie kontakty\n");
        printf("5. Wyjdz\n");
        printf("Wybierz opcje: ");
        scanf("%d", &opcja);

        switch (opcja)
        {
            case 1:
                dodaj(ksiazka_adresowa, &liczba_kontaktow);
                break;
            case 2:
                znajdzNazwisko(ksiazka_adresowa, liczba_kontaktow);
                break;
            case 3:
                usunPoNazwisku(ksiazka_adresowa, &liczba_kontaktow);
                break;
            case 4:
                wypiszKontakty(ksiazka_adresowa, liczba_kontaktow);
                break;
            case 5:
                printf("Koniec programu.\n");
                return 0;
            default:
                printf("Niepoprawna opcja.\n");
        }
    }

    return 0;
}
