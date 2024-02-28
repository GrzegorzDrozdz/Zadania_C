#include <stdio.h>

int silnia_zad3(int n)
{
    if (n == 0)
        return 1;
    else
        return n * silnia_zad3(n - 1);
}

void Zadanie3(int array[], int size)
{
    printf("Silnie dla elementow tablicy:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d! = %d\n", array[i], silnia_zad3(array[i]));
    }
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11,12,13,14,15};
    int size = sizeof(array) / sizeof(array[0]);
    Zadanie3(array, size);
    return 0;
}
