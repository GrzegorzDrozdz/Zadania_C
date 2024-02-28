#include <stdio.h>
int Zadanie5(int liczba)
{
    if (liczba<0)
    {return 0;}
    else
    {
        int suma = 0;
        for(int i = 0; i < liczba;i++)
        {
            if (i % 3 == 0 || i % 5 == 0)
            {
                suma += i;}
        }
        return suma;
    }

}
int main()
{
    printf("suma = %d\n", Zadanie5(10));

    printf("suma = %d\n", Zadanie5(-23));

}
