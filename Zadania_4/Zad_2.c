#include <stdio.h>

int WyszukiwanieBinarne(int tablica[], int lewyIndex, int prawyIndex, int szukany)
{
    if (prawyIndex >= lewyIndex)
    {
        int srodek = lewyIndex + (prawyIndex - lewyIndex) / 2;

        if (tablica[srodek] == szukany)
        {
            return srodek;
        }

        else if (tablica[srodek] > szukany)
        {
            return WyszukiwanieBinarne(tablica, lewyIndex, srodek - 1, szukany);
        }
        else
        {
            return WyszukiwanieBinarne(tablica, srodek + 1, prawyIndex, szukany);
        }
    }


    return -1;
}

int main() {
    int tablica[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(tablica) / sizeof(tablica[0]);
    int szukany = 18;
    int wynik = WyszukiwanieBinarne(tablica, 0, n - 1, szukany);
    if (wynik == -1)
        printf("brak elementu %d w tablicy\n", szukany);
    else
        printf("element %d jest na indexsie %d\n", szukany, wynik);
    return 0;
}
