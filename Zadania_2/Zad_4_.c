#include <stdio.h>
#include <string.h>

typedef struct
{
    char imie[100];
    float ocena;
} Student;

void sort(Student *studenci, int rozmiar)
{
    for (int i = 0; i < rozmiar - 1; i++)
    {
        for (int j = 0; j < rozmiar - i - 1; j++)
        {
            if (studenci[j].ocena < studenci[j + 1].ocena)
            {
                Student temp = studenci[j];
                studenci[j] = studenci[j + 1];
                studenci[j + 1] = temp;
            }
        }
    }
}

int main() {
    Student studenci[] = {
            {"Konrad", 1.0},
            {"Dawid", 3.7},
            {"Oskar", 5.0},
            {"Jakub", 4.7},
            {"Pawel", 4.7}
    };

    int rozmiar = sizeof(studenci) / sizeof(studenci[0]);

    sort(studenci, rozmiar);

    printf("Posortowana lista studentow:\n");
    for (int i = 0; i < rozmiar; i++)
    {
        printf("student: %s - ocena: %.2f\n", studenci[i].imie, studenci[i].ocena);
    }

    return 0;
}
