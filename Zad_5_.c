#include <stdio.h>
#include <string.h>

typedef struct
{
    char imie[100];
    char nazwisko [100];
    char numer_telefonu[14];
} Contact;

Contact ksiazka_adresowa[100];
int liczba_kontaktow = 0;

void dodaj()
{
    if (liczba_kontaktow < 100)
    {
        Contact nowy_kontakt;
        printf("Podaj imie: ");
        scanf("%s", nowy_kontakt.imie);

        printf("Podaj nazwisko: ");
        scanf("%s", nowy_kontakt.nazwisko);

        printf("Podaj nr tel: ");
        scanf("%s", nowy_kontakt.numer_telefonu);

        ksiazka_adresowa[liczba_kontaktow++] = nowy_kontakt;

        printf("Kontakt dodany.\n");
    }
    else
    {
        printf("osiagnieto max kontaktow .\n");
    }
}

void znajdzNazwisko(char nazwisko[])
{
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
    if (znaleziono==0)
    {
        printf("Nie znaleziono.\n");
    }
}

void usunPoNazwisku(char nazwisko[])
{
    int znaleziono = 0;
    for (int i = 0; i < liczba_kontaktow; i++)
    {
        if (strcmp(ksiazka_adresowa[i].nazwisko, nazwisko) == 0)
        {
            for (int j = i; j < liczba_kontaktow - 1; j++) {
                ksiazka_adresowa[j] = ksiazka_adresowa[j + 1];
            }
            liczba_kontaktow--;
            printf("Kontakt o nazwisku %s usunieto.\n", nazwisko);
            znaleziono = 1;
            break;
        }
    }
    if (znaleziono==0)
    {
        printf("Nie znaleziono\n");
    }
}

void wypiszKontakty() {
    printf("Ksiazka adresowa:\n");
    for (int i = 0; i < liczba_kontaktow; i++)
    {
        printf("Kontakt %d:\n", i + 1);
        printf("Imie: %s\n", ksiazka_adresowa[i].imie);
        printf("Nazwisko: %s\n", ksiazka_adresowa[i].nazwisko);
        printf("Nr tel: %s\n", ksiazka_adresowa[i].numer_telefonu);
    }
}

int main() {
    int opcja;
    char nazwisko[100];

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

        switch (opcja) {
            case 1:
                dodaj();
                break;
            case 2:
                printf("Podaj nazwisko kontaktu do wyszukania: ");
                scanf("%s", nazwisko);
                znajdzNazwisko(nazwisko);
                break;
            case 3:
                printf("Podaj nazwisko kontaktu do usuniecia: ");
                scanf("%s", nazwisko);
                usunPoNazwisku(nazwisko);
                break;
            case 4:
                wypiszKontakty();
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
