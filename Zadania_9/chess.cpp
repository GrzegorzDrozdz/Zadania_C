#include <iostream>
#include<windows.h>
using namespace std ;



void displayGameRules() {
    cout <<"KROL - jedno pole w kazdym kierunku\n"
            "GONIEC - po przekatnej planszy\n"
            "WIEZA - poziomo lub pionowo\n"
            "KROLOWA - pionowo/poziomo lub po przekatnych\n"
            "SKOCZEK - przesuwa sie o dwa pola w dowolnie wybranym (pionowym/poziomym) kierunku, a następnie o jedno pole w kierunku prostopadlym.\n" << endl;

}
int currentPlayer=0;
int move=0;
const int boardSize = 8;

//inicjalizacja planszy
char board[boardSize][boardSize] = {
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
};
//wyświetlanie planszy
void printBoard(char board[boardSize][boardSize]) {
    cout<<"  0   1   2   3   4   5   6   7\n";
    for(int i=0; i<8; i++) {
        cout << "+---+---+---+---+---+---+---+---+" << endl;
        for(int j=0; j<8; j++) {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|" << " "<<i<< endl;
    }
    cout << "+---+---+---+---+---+---+---+---+" << endl;

}

//król
bool MoveKing( int old_x, int old_y, int new_x, int new_y) {

// sprawdzam czy początkowa pozycja okraz pozycja końcowa mieszczą się na planszy
    if (old_x < 0 || old_x >= 8 || old_y < 0 || old_y >= 8 ){ return false;}
    if( new_x < 0 || new_x >= 8 || new_y < 0 || new_y >= 8) {return false;}

//Sprawdzam, czy pozycja początkowa zawiera figurę należącą do tego samego gracza
    if ((board[old_x][old_y] >= 'A' && board[old_x][old_y] <= 'Z') && (board[new_x][new_y] >= 'A' && board[new_x][new_y] <= 'Z')) {return false;}
    if ((board[old_x][old_y] >= 'a' && board[old_x][old_y] <= 'z') && (board[new_x][new_y] >= 'a' && board[new_x][new_y] <= 'z')) {return false;}


// Obliczam bezwzględne różnice w pozycjach
    double diffY = abs(new_y - old_y);
    double diffX = abs(new_x - old_x);

    if (diffX <= 1 && diffY <= 1) {return true;}
    return false;
}

//goniec
bool MoveBishop( int old_x, int old_y, int new_x, int new_y) {

    // sprawdzam czy początkowa pozycja okraz pozycja końcowa mieszczą się na planszy
    if (old_x < 0 || old_x >= 8 || old_y < 0 || old_y >= 8 ){ return false;}
    if( new_x < 0 || new_x >= 8 || new_y < 0 || new_y >= 8) {return false;}

//Sprawdzam, czy pozycja początkowa zawiera figurę należącą do tego samego gracza
    if ((board[old_x][old_y] >= 'A' && board[old_x][old_y] <= 'Z') && (board[new_x][new_y] >= 'A' && board[new_x][new_y] <= 'Z')) {return false;}
    if ((board[old_x][old_y] >= 'a' && board[old_x][old_y] <= 'z') && (board[new_x][new_y] >= 'a' && board[new_x][new_y] <= 'z')) {return false;}

// Obliczam bezwzględne różnice w pozycjach
    int diffX = abs(new_x - old_x);
    int diffY = abs(new_y - old_y);

// sprawdzenie czy ruch jest po skosie wtedy X i Y są takie same
    if (diffX == diffY)
    {
        int stepX;
        int stepY;
        // jeśli new_x jest większy niż new_x ==> stepX= 1 Goniec idzie w prawo gdy stepX= -1 idzie w lewo analogicznie stepY
        if (new_x > old_x)
        {
            stepX = 1;
        } else
        {
            stepX = -1;
        }

        if (new_y > old_y)
        {
            stepY = 1;
        } else
        {
            stepY = -1;
        }

        int x = old_x + stepX;
        int y = old_y + stepY;

        // Sprawdzam, czy na drodze gońca nie znajdują się jakieś przeszkody które by blokowały ruch
        while (x != new_x && y != new_y)
        {
            if (board[x][y] != ' ')
            {
            // goniec napotkał przeszkodę na swojej drodzę wiec ruch jest niemożlwiy
                return false;
            }

            x += stepX;
            y += stepY;
        }


        return true;
    }


    return false;
}

//wieża
bool MoveRook( int old_x, int old_y, int new_x, int new_y) {

    // sprawdzam czy początkowa pozycja okraz pozycja końcowa mieszczą się na planszy
    if (old_x < 0 || old_x >= 8 || old_y < 0 || old_y >= 8 ){ return false;}
    if( new_x < 0 || new_x >= 8 || new_y < 0 || new_y >= 8) {return false;}

//Sprawdzam, czy pozycja początkowa zawiera figurę należącą do tego samego gracza
    if ((board[old_x][old_y] >= 'A' && board[old_x][old_y] <= 'Z') && (board[new_x][new_y] >= 'A' && board[new_x][new_y] <= 'Z')) {return false;}
    if ((board[old_x][old_y] >= 'a' && board[old_x][old_y] <= 'z') && (board[new_x][new_y] >= 'a' && board[new_x][new_y] <= 'z')) {return false;}


// Obliczam bezwzględne różnice w pozycjach
    int diffX = abs(new_x - old_x);
    int diffY = abs(new_y - old_y);
// skrawdzam czy ruch jest poziomy lub pionowy
    if ((diffX > 0 && diffY == 0) || (diffX == 0 && diffY > 0))
    {

        int stepX;
        int stepY;
        //ruch na osi X
        if (new_x > old_x) {
            stepX = 1; // prawo
        } else if (new_x < old_x) {
            stepX = -1; //lewo
        } else {
            stepX = 0; //brak
        }
        //ruch na osi y
        if (new_y > old_y) {
            stepY = 1; // góra
        } else if (new_y < old_y) {
            stepY = -1; //dół
        } else {
            stepY = 0; //bral
        }

// Sprawdzam, czy na drodze nie znajdują się jakieś przeszkody które by blokowały ruch
        int x = old_x + stepX;
        int y = old_y + stepY;
        while (x != new_x || y != new_y) {
            if (board[x][y] != ' ') {

                return false;
            }
            x += stepX;
            y += stepY;
        }


        return true;
    }


    return false;
}

// królowa czyli hetman
bool MoveQueen(int old_x, int old_y, int new_x, int new_y) {

    // sprawdzam czy początkowa pozycja okraz pozycja końcowa mieszczą się na planszy
    if (old_x < 0 || old_x >= 8 || old_y < 0 || old_y >= 8 ){ return false;}
    if( new_x < 0 || new_x >= 8 || new_y < 0 || new_y >= 8) {return false;}

//Sprawdzam, czy pozycja początkowa zawiera figurę należącą do tego samego gracza
    if ((board[old_x][old_y] >= 'A' && board[old_x][old_y] <= 'Z') && (board[new_x][new_y] >= 'A' && board[new_x][new_y] <= 'Z')) {return false;}
    if ((board[old_x][old_y] >= 'a' && board[old_x][old_y] <= 'z') && (board[new_x][new_y] >= 'a' && board[new_x][new_y] <= 'z')) {return false;}


// Obliczam bezwzględne różnice w pozycjach
    int diffX = abs(new_x - old_x);
    int diffY = abs(new_y - old_y);

    // analogicznie jak wieża - skrawdzam czy ruch jest poziomy lub pionowy
    if ((diffX > 0 && diffY == 0) || (diffX == 0 && diffY > 0))
    {

        int stepX, stepY;
        if (new_x > old_x) {
            stepX = 1;// Ruch w prawo
        } else if (new_x < old_x) {
            stepX = -1;// Ruch w lewo
        } else {
            stepX = 0; // brak ruchu
        }

        if (new_y > old_y)
        {
            stepY = 1;// Ruch w górę
        } else if (new_y < old_y)
        {
            stepY = -1;// Ruch w dół
        } else
        {
            stepY = 0; // Brak ruchu w osi Y
        }

        int x = old_x + stepX;
        int y = old_y + stepY;

        // sprawdzam czy na drodze jest inna figura
        while (x != new_x || y != new_y)
        {
            if (board[x][y] != ' ')
            {

                if ((board[x][y] == 'k' || board[x][y] == 'K') && (diffX == 1 || diffY == 1)) {return false;}
                return false;// Inna figura blokuje drogę
            }
            x += stepX;// Przesunięcie w osi X
            y += stepY;// Przesunięcie w osi Y
        }


        return true;// Ruch jest możliwi
    }
        // Sprawdzenie, czy ruch jest po przekątnej
    else if (diffX == diffY) {

        int stepX, stepY;
        if (new_x > old_x)  {
            stepX = 1;// Ruch w prawo
        } else {
            stepX = -1;// Ruch w lewo po przekątnej
        }
        if (new_y > old_y) {
            stepY = 1;// Ruch w górę po przekątnej
        } else {
            stepY = -1; // Ruch w dół
        }

        int x = old_x + stepX;
        int y = old_y + stepY;
       // Iterowanie po drodze do nowej pozycji
        while (x != new_x && y != new_y)
        {
            if (board[x][y] != ' ')  // Jeśli na drodze jest inna figura
            {
                if ((board[x][y] == 'k' || board[x][y] == 'K') && (diffX == 1 || diffY == 1))
                {
                    return false;
                }


                return false;
            }
            x += stepX; //Przesunięcie w osi Y
            y += stepY; // Przesunięcie w osi Y
        }


        return true;
    }


    return false;
}

//skoczek czyli konik
bool MoveKnight( int old_x, int old_y, int new_x, int new_y)
{
    // sprawdzam czy początkowa pozycja okraz pozycja końcowa mieszczą się na planszy
    if (old_x < 0 || old_x >= 8 || old_y < 0 || old_y >= 8 ){ return false;}
    if( new_x < 0 || new_x >= 8 || new_y < 0 || new_y >= 8) {return false;}

//Sprawdzam, czy pozycja początkowa zawiera figurę należącą do tego samego gracza
    if ((board[old_x][old_y] >= 'A' && board[old_x][old_y] <= 'Z') && (board[new_x][new_y] >= 'A' && board[new_x][new_y] <= 'Z')) {return false;}
    if ((board[old_x][old_y] >= 'a' && board[old_x][old_y] <= 'z') && (board[new_x][new_y] >= 'a' && board[new_x][new_y] <= 'z')) {return false;}


// Obliczam bezwzględne różnice w pozycjach
    int diffX = abs(new_x - old_x);
    int diffY = abs(new_y - old_y);


    // przesuwa się o dwa pola w dowolnie wybranym (pionowym/poziomym) kierunku, a następnie o jedno pole w kierunku prostopadłym.
    if ((diffX == 2 && diffY == 1) || (diffX == 1 && diffY == 2))
    {
        return true;
    }

    return false;
}

// ruch białych czy czarnych
int getPlayer(char piece)
{

    if (piece >= 'a' && piece <= 'z')
    {

        return 1;
    } else if (piece >= 'A' && piece <= 'Z')
    {

        return 2;
    }

    return 0;
}

//sprawdzam czy ruch figury kończy się na polu zajmowanym przez własną figurę
bool capturesOwnPiece(char board[boardSize][boardSize], int old_x, int old_y, int new_x, int new_y)
{

    char startPiece = board[old_x][old_y]; //figura która obecnie znajduje się na polu
    char endPiece = board[new_x][new_y]; //figura która pojawi się na polu

    if (startPiece == ' ' || endPiece == ' ') //puste pole
    {

        return false;
    }

    // Pobiera numer gracza
    int startPlayer = getPlayer(startPiece);
    int endPlayer = getPlayer(endPiece);

// Jeśli figura startowa i końcowa należą do tego samego gracza
    if (startPlayer == endPlayer)
    {
        return true;  // Ruch bije własną figurę, zwraca true
    }

    return false; // W przeciwnym razie ruch nie bije własnej figury
}

//czy ruch figury z pozycji jest możliwy
bool isValidMove(int old_x, int old_y, int new_x, int new_y) {

    // sprawdzam czy początkowa pozycja okraz pozycja końcowa mieszczą się na planszy
    if (old_x < 0 || old_x >= 8 || old_y < 0 || old_y >= 8 ){ return false;}
    if( new_x < 0 || new_x >= 8 || new_y < 0 || new_y >= 8) {return false;}
// Sprawdzam, czy na początkowej pozycji jest jakaś figura
    if (board[old_x][old_y] == ' ')
    {
        return false;// Puste pole, nie ma figury do ruszenia
    }
//Sprawdzam, czy na końcowej pozycji nie znajduje się własna figura
    if (board[new_x][new_y] !=' ' && board[old_x][old_y] == board[new_x][new_y])
    {
        return false;
    }
// Sprawdzam rodzaj figury i wywołuję odpowiednią funkcję ruchu
    switch (board[old_x][old_y]) {

        case 'K':
            return MoveKing(old_x, old_y, new_x, new_y);
            break;
        case 'k':
            return MoveKing(old_x, old_y, new_x, new_y);
            break;
        case 'N':
            return MoveKnight(old_x, old_y, new_x, new_y);
            break;
        case 'n':
            return MoveKnight(old_x, old_y, new_x, new_y);
        case 'Q':
            return MoveQueen(old_x, old_y, new_x, new_y);
            break;
        case 'q':
            return MoveQueen(old_x, old_y, new_x, new_y);
        case 'R':
            return MoveRook(old_x, old_y, new_x, new_y);
            break;
        case 'r':
            return MoveRook(old_x, old_y, new_x, new_y);
            break;
        case 'B':
            return MoveBishop(old_x, old_y, new_x, new_y);
            break;
        case 'b':
            return MoveBishop(old_x, old_y, new_x, new_y);
            break;
        default:
            return false;
            break;
    }
}

//poprawne ruchy dla figury
void showValidMoves(char board[boardSize][boardSize], int old_x, int old_y) {
    // Pobieramy współrzędne figury z pozycji startowej
    char piece = board[old_x][old_y];
    // Sprawdzamy, czy na polu startowym jest figura
    if ((piece >= 'a' && piece <= 'z')||( piece >= 'A' && piece <='Z'))
    {
        cout << "Valid moves for the selected piece (" << piece << ") at position (" << old_x << ", " << old_y << "):" << endl;
// Iteruje po wszystkich pozycjach na planszy
        for (int new_x = 0; new_x < 8; new_x++) {
            for (int new_y = 0; new_y < 8; new_y++) {

                bool isValidMove = false;// Zmienna do przechowywania wyniku sprawdzenia ruchu
                // Sprawdzamy rodzaj figury i wywołujemy odpowiednią funkcję ruchu
                switch (tolower(piece)) {

                    case 'r':
                        isValidMove =MoveRook( old_x, old_y, new_x, new_y);
                        break;
                    case 'R':
                        isValidMove =MoveRook( old_x, old_y, new_x, new_y);
                        break;
                    case 'N':
                        isValidMove = MoveKnight( old_x, old_y, new_x, new_y);
                        break;
                    case 'n':
                        isValidMove = MoveKnight( old_x, old_y, new_x, new_y);
                        break;
                    case 'b':
                        isValidMove = MoveBishop( old_x, old_y, new_x, new_y);
                        break;
                    case 'B':
                        isValidMove = MoveBishop( old_x, old_y, new_x, new_y);
                        break;
                    case 'q':
                        isValidMove =MoveQueen( old_x, old_y, new_x, new_y);
                        break;
                    case 'Q':
                        isValidMove =MoveQueen( old_x, old_y, new_x, new_y);
                        break;
                    case 'k':
                        isValidMove = MoveKing(old_x, old_y, new_x, new_y);
                        break;
                    case 'K':
                        isValidMove = MoveKing(old_x, old_y, new_x, new_y);
                        break;
                }

                // Jeśli ruch jest poprawny i nie bije własnej figury
                if (isValidMove && !capturesOwnPiece(board, old_x, old_y, new_x, new_y)) {
                    // Wyświetlam poprawny ruch
                    cout << "(" << old_x << ", " << old_y << ") -> (" << new_x << ", " << new_y << ")" << endl;

                }
            }
        }
    }
    else {
        // Jeśli na polu startowym nie ma figury, wyświetlamy komunikat o braku poprawnych ruchów
        cout << "No valid moves. Please select a valid piece." << endl;

    }
}

//Czy szach
bool isInCheck(const char board[boardSize][boardSize], int currentPlayer) {
//pozycja króla
    int kingX = -1;
    int kingY = -1;
    char kingPiece = (currentPlayer == 1) ? 'K' : 'k';   // 1 dla białego króla 'K', 2 dla czarnego króla 'k'
    // Szukamy pozycji króla na planszy
    for (int x = 0; x < 8; x++)
    {
        for (int y = 0; y < 8; y++)
        {
            if (board[x][y] == kingPiece)
            {
                kingX = x;
                kingY = y;
                break; // jak już się odnalazł to go dalej nie szukam
            }
        }
        if (kingX != -1 && kingY != -1)
        {
            break;
        }
    }

    // Przechodzimy przez wszystkie figury przeciwnika i sprawdzamy, czy mogą one zaatakować króla
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            char piece = board[x][y];

// Sprawdzamy figury przeciwnika: małe litery dla gracza 1, wielkie dla gracza 2
            if ((currentPlayer == 1 && islower(piece)) ||
                (currentPlayer == 2 && isupper(piece))) {

                // Sprawdzamy, czy figura przeciwnika może wykonać ruch na pozycję króla
                if (isValidMove( x, y, kingX, kingY)) {
                    // Jeśli ruch jest możliwy, król jest w szachu
                    return true;
                }
            }
        }
    }
// Jeśli ruch jest nie możliwy, król nie jest w szachu
    return false;
}
// koniec gry
bool gameOver(char board[boardSize][boardSize], int currentPlayer) {

    if (isInCheck(board,currentPlayer))
    {
        cout << "Game Over! Player " << currentPlayer << " is in checkmate." << endl;
        return true;
    }

    return false;

}

// Sprawdza, czy wybrana figura jest prawidłowa
bool isValidPiece(char choice, char currentPlayer) {
    if (currentPlayer == 1) {
        return choice == 'R' || choice == 'K' || choice == 'Q' || choice == 'N' || choice == 'B';
    } else {
        return choice == 'r' || choice == 'k' || choice == 'q' || choice == 'n' || choice == 'b';
    }
}

// Sprawdza, czy figura jest na planszy
bool isPieceOnBoard(char board[8][8], char choice, int &old_x, int &old_y) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == choice) {
                old_x = i;
                old_y = j;
                return true;
            }
        }
    }
    return false;
}

// Pobiera współrzędne startowe figury od gracza
void getStartCoordinates(char board[8][8], char choice, int &old_x, int &old_y) {
    while (true) {
        cout << "Enter start position of piece " << choice << " as coordinates (y,x) \n";
        cin >> old_x >> old_y;

        if (old_x >= 0 && old_x < 8 && old_y >= 0 && old_y < 8 && board[old_x][old_y] == choice) {
            break;
        } else {
            cout << "Invalid position or your desired piece isn't in that location\n";
            cout << "Please enter again\n";
        }
    }
}

int playGame() {
    cout << "Enter which piece you want to move\n";
    int old_x, old_y, new_x, new_y;

    while (true) { // Pętla główna gry
        cout << endl << endl;
        char choice;
        while (true) {
            currentPlayer = 1;
            printBoard(board);
            cout << "Player " << currentPlayer << " (white)\n ";

            while (true) { // Pętla dla wyboru figury przez gracza 1
                cout << "Enter name of piece (R,K,Q,N,B) you want to move\n";
                cin >> choice;

                if (!isValidPiece(choice, currentPlayer)) {
                    cout << "wrong name\n";
                    continue;
                }

                if (choice == 'R' || choice == 'K' || choice == 'Q' || choice == 'N' || choice == 'B') {
                    if (!isPieceOnBoard(board, choice, old_x, old_y)) {
                        cout << "piece has been killed\n";
                        continue;
                    }
                    break;
                }
            }

            getStartCoordinates(board, choice, old_x, old_y);  // Pobranie współrzędnych startowych figury
            showValidMoves(board, old_x, old_y); // Wyświetlenie możliwych ruchów
            cin >> new_x >> new_y;// Pobranie współrzędnych docelowych

            if (isValidMove(old_x, old_y, new_x, new_y)) { // Sprawdzenie, czy ruch jest poprawny
                board[new_x][new_y] = board[old_x][old_y];  // Wykonanie ruchu na planszy
                board[old_x][old_y] = ' '; // Usunięcie figury ze starej pozycji
                break;
            } else {
                cout << "Invalid move! Try again." << endl;
                continue;
            }
        }

        if (gameOver(board, currentPlayer)) // Sprawdzenie, czy gra się zakończyła
            break;

        currentPlayer = 2; // Ustawienie bieżącego gracza na gracza 2
        while (true) {  // Pętla dla drugiego gracza
            printBoard(board);
            cout << "Player " << currentPlayer << " (Black)\n ";

            while (true) {
                cout << "Enter name of piece (r,k,q,n,b) you want to move\n";
                cin >> choice;

                if (!isValidPiece(choice, currentPlayer)) { // Sprawdzenie, czy wybrana figura jest poprawna dla gracza 2
                    cout << "Enter correct name of piece\n";
                    continue;
                }

                if (choice == 'r' || choice == 'k' || choice == 'q' || choice == 'n' || choice == 'b') {
                    if (!isPieceOnBoard(board, choice, old_x, old_y)) {  // Sprawdzenie, czy wybrana figura jest na planszy
                        cout << "The piece has been killed by the opponent\n";
                        continue;
                    }
                    break;
                }
            }

            getStartCoordinates(board, choice, old_x, old_y);
            showValidMoves(board, old_x, old_y);
            cin >> new_x >> new_y;

            if (isValidMove(old_x, old_y, new_x, new_y)) {
                board[new_x][new_y] = board[old_x][old_y];
                board[old_x][old_y] = ' ';
                break;
            } else {
                cout << "Invalid move! Try again." << endl;
                continue;
            }
        }

        if (gameOver(board, currentPlayer))
            break;
    }
}

int main() {
    int choice;
    do{
        displayGameRules();
        cout << "Play Game = 1\n";
        cout << "Exit = 2\n";

        cout << "Enter your choice: ";
        cin >> choice;
        if(choice ==1){
            cout<<playGame();
            break;
            cout<<endl;
        }
        else if (choice == 2)
        {
            cout << "Exiting the game. Goodbye!" << endl;
        }
        else
        {
            cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 3);
    return 0;
}
