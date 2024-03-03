#include <stdio.h>

typedef struct
{
    int x;
    int y;
}  Point;

void Nowe_xy (Point *punkt, int n_x, int n_y)
{
    punkt->x = n_x;
    punkt->y = n_y;
}


typedef struct
{
    Point lewy_gorny;
    Point prawy_dolny;
}  Rectangle;


int Pole(Rectangle *prostokat)
{
    int a = prostokat->prawy_dolny.x - prostokat->lewy_gorny.x;
    int b = prostokat->lewy_gorny.y - prostokat->prawy_dolny.y;
    return a * b;
}

int Obwod(Rectangle *prostokat)
{
    int wysokosc = prostokat->lewy_gorny.y - prostokat->prawy_dolny.y;
    int szerokosc = prostokat->prawy_dolny.x - prostokat->lewy_gorny.x;
    return 2 * (szerokosc + wysokosc);
}

int main()
{
    Point p1 = {5, 15};
    printf("wspolrzedne: (%d, %d)\n", p1.x, p1.y);

    Nowe_xy(&p1, 6, 9);

    printf("Nowe wspolrzedne: (%d, %d)\n", p1.x, p1.y);

    Rectangle prostokat = {{3, 12}, {5, 1}};

    int pole = Pole(&prostokat);
    int obwod = Obwod(&prostokat);

    printf("Pole prostokata: %d\n", pole);
    printf("Obwod prostokata: %d\n", obwod);

    return 0;
}
