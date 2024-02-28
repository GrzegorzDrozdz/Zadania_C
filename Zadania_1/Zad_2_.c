#include <stdio.h>

void Zadanie2(){
    int grades[2][5];
    printf("Podaj oceny z matematyki dla 5 uczniow:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Uczen %d: ", i + 1);
        scanf("%d", &grades[0][i]);
    }

    printf("Podaj oceny z fizyki dla 5 uczniow:\n");
    for (int i = 0; i < 5; i++) {
        printf("Uczen %d: ", i + 1);
        scanf("%d", &grades[1][i]);
    }

    int sumMath = 0;
    for (int i = 0; i < 5; i++)
    {
        sumMath += grades[0][i];
    }
    float avgMath = (float)sumMath / 5;

    int sumPhysics = 0;
    for (int i = 0; i < 5; i++) {
        sumPhysics += grades[1][i];
    }
    float avgPhysics = (float)sumPhysics / 5;

    printf("Srednia ocen z matematyki: %.2f\n", avgMath);
    printf("Srednia ocen z fizyki: %.2f\n", avgPhysics);
}
int main()
{
    Zadanie2();
}