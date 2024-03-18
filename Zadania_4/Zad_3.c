#include <stdio.h>


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int *ciag, int start, int koniec)
{
    if (start == koniec)
    {
        for (int i = 0; i <= koniec; i++)
        {
            printf("%d ", ciag[i]);
        }
        printf("\n");
    }
    else
    {
        for (int i = start; i <= koniec; i++)
        {
            swap(&ciag[start], &ciag[i]);

            permute(ciag, start + 1, koniec);

            swap(&ciag[start], &ciag[i]);
        }
    }
}

int main() {
    int ciag[] = {1, 2, 3};
    int n = sizeof(ciag) / sizeof(ciag[0]);

    printf("Permutacje ciagu:\n");
    permute(ciag, 0, n - 1);

    return 0;
}
