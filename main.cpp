#include <iostream>
#include<windows.h>
using namespace std ;


void displayGameRules() {
    cout << "***GAME RULES***" << endl;
    cout << "-SELECT THE FIGURE YOU WANT TO MAKE A MOVEMENT EG White-(R K Q N B) Black-(r k q n b)" << endl;
    cout << "-ENTER THE STARTING POSITION OF THIS FIGURE EG (height,width)" << endl;
    cout << "-FROM THE MOVEMENT OPTIONS DISPLAYED, SELECT THE MOVEMENT YOU WANT TO MAKE" << endl;
    cout << "GOOD LUCK AND HAVE FUN!" << endl;
}



int currentPlayer=0;
int move=0;
const int boardSize = 8;

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
bool isWithinBounds(int x, int y) {
    return (x >= 0 && x < boardSize && y >= 0 && y < boardSize);
}

bool MoveKing( int old_x, int old_y, int new_x, int new_y) {

    if (old_x < 0 || old_x >= 8 || old_y < 0 || old_y >= 8 )
        return false;

    if( new_x < 0 || new_x >= 8 || new_y < 0 || new_y >= 8) {
        return false;
    }

    if ((board[old_x][old_y] >= 'A' && board[old_x][old_y] <= 'Z') && (board[new_x][new_y] >= 'A' && board[new_x][new_y] <= 'Z')) {
        return false;
    }

    if ((board[old_x][old_y] >= 'a' && board[old_x][old_y] <= 'z') && (board[new_x][new_y] >= 'a' && board[new_x][new_y] <= 'z')) {
        return false;
    }


    double diffY = abs(new_y - old_y);
    double diffX = abs(new_x - old_x);

    if (diffX <= 1 && diffY <= 1) {

        return true;
    }


    return false;
}

bool MoveBishop( int old_x, int old_y, int new_x, int new_y) {

    if (old_x < 0 || old_x >= 8 || old_y < 0 || old_y >= 8 )
        return false;

    if( new_x < 0 || new_x >= 8 || new_y < 0 || new_y >= 8) {
        return false;
    }

    if ((board[old_x][old_y] >= 'a' && board[old_x][old_y] <= 'z') && (board[new_x][new_y] >= 'a' && board[new_x][new_y] <= 'z')) {
        return false;
    }
    if ((board[old_x][old_y] >= 'A' && board[old_x][old_y] <= 'Z') && (board[new_x][new_y] >= 'A' && board[new_x][new_y] <= 'Z')) {
        return false;
    }


    int diffX = abs(new_x - old_x);
    int diffY = abs(new_y - old_y);


    if (diffX == diffY) {

        int stepX;
        int stepY;

        if (new_x > old_x) {
            stepX = 1;
        } else {
            stepX = -1;
        }

        if (new_y > old_y) {
            stepY = 1;
        } else {
            stepY = -1;
        }

        int x = old_x + stepX;
        int y = old_y + stepY;

        while (x != new_x && y != new_y) {
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


bool MoveRook( int old_x, int old_y, int new_x, int new_y) {

    if (old_x < 0 || old_x >= 8 || old_y < 0 || old_y >= 8 ||
        new_x < 0 || new_x >= 8 || new_y < 0 || new_y >= 8) {
        return false;
    }


    if ((board[old_x][old_y] >= 'a' && board[old_x][old_y] <= 'z') && (board[new_x][new_y] >= 'a' && board[new_x][new_y] <= 'z')) {
        return false;
    }
    if ((board[old_x][old_y] >= 'A' && board[old_x][old_y] <= 'Z') && (board[new_x][new_y] >= 'A' && board[new_x][new_y] <= 'Z')) {
        return false;
    }


    int diffX = abs(new_x - old_x);
    int diffY = abs(new_y - old_y);

    if ((diffX > 0 && diffY == 0) || (diffX == 0 && diffY > 0)) {

        int stepX;
        int stepY;

        if (new_x > old_x) {
            stepX = 1;
        } else if (new_x < old_x) {
            stepX = -1;
        } else {
            stepX = 0;
        }

        if (new_y > old_y) {
            stepY = 1;
        } else if (new_y < old_y) {
            stepY = -1;
        } else {
            stepY = 0;
        }


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


bool MoveQueen(int old_x, int old_y, int new_x, int new_y) {

    if (old_x < 0 || old_x >= 8 || old_y < 0 || old_y >= 8 ||
        new_x < 0 || new_x >= 8 || new_y < 0 || new_y >= 8) {
        return false;
    }


    if ((board[old_x][old_y] >= 'a' && board[old_x][old_y] <= 'z') && (board[new_x][new_y] >= 'a' && board[new_x][new_y] <= 'z') ) {
        return false;
    }
    if ((board[old_x][old_y] >= 'A' && board[old_x][old_y] <= 'Z') && (board[new_x][new_y] >= 'A' && board[new_x][new_y] <= 'Z')) {
        return false;
    }


    int diffX = abs(new_x - old_x);
    int diffY = abs(new_y - old_y);


    if ((diffX > 0 && diffY == 0) || (diffX == 0 && diffY > 0)) {

        int stepX, stepY;
        if (new_x > old_x) {
            stepX = 1;
        } else if (new_x < old_x) {
            stepX = -1;
        } else {
            stepX = 0;
        }

        if (new_y > old_y) {
            stepY = 1;
        } else if (new_y < old_y) {
            stepY = -1;
        } else {
            stepY = 0;
        }

        int x = old_x + stepX;
        int y = old_y + stepY;

        while (x != new_x || y != new_y) {
            if (board[x][y] != ' ') {

                if ((board[x][y] == 'k' || board[x][y] == 'K') && (diffX == 1 || diffY == 1)) {
                    return false;
                }
                return false;
            }
            x += stepX;
            y += stepY;
        }


        return true;
    }

    else if (diffX == diffY) {

        int stepX, stepY;
        if (new_x > old_x)  {
            stepX = 1;
        } else {
            stepX = -1;
        }
        if (new_y > old_y) {
            stepY = 1;
        } else {
            stepY = -1;
        }

        int x = old_x + stepX;
        int y = old_y + stepY;

        while (x != new_x && y != new_y) {
            if (board[x][y] != ' ') {
                if ((board[x][y] == 'k' || board[x][y] == 'K') && (diffX == 1 || diffY == 1)) {
                    return false;
                }


                return false;
            }
            x += stepX;
            y += stepY;
        }


        return true;
    }


    return false;
}

bool MoveKnight( int old_x, int old_y, int new_x, int new_y) {

    if (old_x < 0 || old_x >= 8 || old_y < 0 || old_y >= 8 ||
        new_x < 0 || new_x >= 8 || new_y < 0 || new_y >= 8) {
        return false;
    }


    if ((board[old_x][old_y] >= 'a' && board[old_x][old_y] <= 'z') && (board[new_x][new_y] >= 'a' && board[new_x][new_y] <= 'z') && (board[new_x][new_y]=='K')) {
        return false;
    }
    if ((board[old_x][old_y] >= 'A' && board[old_x][old_y] <= 'Z') && (board[new_x][new_y] >= 'A' && board[new_x][new_y] <= 'Z') && (board[new_x][new_y]=='K')) {
        return false;
    }

    int diffX = abs(new_x - old_x);
    int diffY = abs(new_y - old_y);


    if ((diffX == 2 && diffY == 1) || (diffX == 1 && diffY == 2)) {

        return true;

    }


    return false;
}

int getPlayer(char piece) {

    if (piece >= 'a' && piece <= 'z') {

        return 1;
    } else if (piece >= 'A' && piece <= 'Z') {

        return 2;
    }

    return 0;
}

bool capturesOwnPiece(char board[boardSize][boardSize], int old_x, int old_y, int new_x, int new_y) {

    char startPiece = board[old_x][old_y];
    char endPiece = board[new_x][new_y];

    if (startPiece == ' ' || endPiece == ' ') {

        return false;
    }

    int startPlayer = getPlayer(startPiece);
    int endPlayer = getPlayer(endPiece);


    if (startPlayer == endPlayer) {
        return true;
    }

    return false;
}

bool isValidMove(int old_x, int old_y, int new_x, int new_y) {

    if (old_x < 0 || old_x >= 8|| old_y < 0 || old_y >= 8) {
        return false;
    }

    if (new_x < 0 || new_x >= 8 || new_y < 0 || new_y >= 8) {
        return false;
    }

    if (board[old_x][old_y] == ' ') {
        return false;
    }

    if (board[new_x][new_y] !=' ' && board[old_x][old_y] == board[new_x][new_y]) {
        return false;
    }

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




void showValidMoves(char board[boardSize][boardSize], int old_x, int old_y) {
    char piece = board[old_x][old_y];

    if ((piece >= 'a' && piece <= 'z')||( piece >= 'A' && piece <='Z')) {
        cout << "Valid moves for the selected piece (" << piece << ") at position (" << old_x << ", " << old_y << "):" << endl;

        for (int new_x = 0; new_x < 8; new_x++) {
            for (int new_y = 0; new_y < 8; new_y++) {

                bool isValidMove = false;

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


                if (isValidMove && !capturesOwnPiece(board, old_x, old_y, new_x, new_y)) {

                    cout << "(" << old_x << ", " << old_y << ") -> (" << new_x << ", " << new_y << ")" << endl;

                }
            }
        }
    }
    else {

        cout << "No valid moves. Please select a valid piece." << endl;

    }
}

void showValidMovesForPlayer(char board[boardSize][boardSize], int currentPlayer) {
    cout << "Valid moves for Player " << currentPlayer << ":" << endl;

    for (int old_x = 0; old_x < 8; old_x++) {
        for (int old_y = 0; old_y < 8; old_y++) {
            char piece = board[old_x][old_y];

            if ((currentPlayer == 1 && (piece >= 'A' && piece <= 'Z')) ||
                (currentPlayer == 2 && (piece >= 'a' && piece <= 'z'))) {

                showValidMoves(board, old_x, old_y);
            }
        }
    }
}

bool isInCheck(const char board[boardSize][boardSize], int currentPlayer) {

    int kingX = -1;
    int kingY = -1;
    char kingPiece = (currentPlayer == 1) ? 'K' : 'k';

    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if (board[x][y] == kingPiece) {
                kingX = x;
                kingY = y;
                break;
            }
        }
        if (kingX != -1 && kingY != -1) {
            break;
        }
    }

    char opponentKingPiece = (currentPlayer == 1) ? 'k' : 'K';

    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            char piece = board[x][y];


            if ((currentPlayer == 1 && islower(piece)) ||
                (currentPlayer == 2 && isupper(piece))) {


                if (isValidMove( x, y, kingX, kingY)) {
                    // The king is in check
                    return true;
                }
            }
        }
    }

    return false;
}

bool gameOver(char board[boardSize][boardSize], int currentPlayer) {

    if (isInCheck(board,currentPlayer)) {
        cout << "Game Over! Player " << currentPlayer << " is in checkmate." << endl;
        return true;
    }

    return false;

}

int playGame() {
    cout << "Enter which piece you want to move\n";
    int old_x, old_y, new_x, new_y;
    while (true) {
        cout<<endl;
        cout<<endl;

        char choice;
        while (true) {
            currentPlayer =1;
            printBoard(board);

            cout << "Player "<< currentPlayer<<" (white)\n ";
            while (true) {
                cout << "Enter name of piece (R,K,Q,N,B) you want to move\n";
                cin >> choice;

                if (choice != 'R' && choice != 'K' && choice != 'Q' && choice != 'N' && choice != 'B') {
                    cout << "wrong name\n";
                    continue;
                }

                if (choice == 'R') {
                    bool pieceFound = false;
                    for(int i = 0; i < 8; i++) {
                        for(int j = 0; j < 8; j++) {
                            if(board[i][j] == choice) {
                                pieceFound = true;
                                break;
                            }
                        }
                        if (pieceFound) {
                            break;
                        }
                    }
                    if (!pieceFound) {
                        cout << "piece has been killed\n";
                        continue;
                    }

                    cout << "Enter start position " << choice << " as coordinates (x,y) \n";
                    cin >> old_x >> old_y;

                    while (old_x < 0 || old_x >= 8 || old_y < 0 || old_y >= 8 || board[old_x][old_y] != choice) {
                        cout << "Invalid position or your desired piece isn't in that location\n";
                        cout << "Please enter again\n";
                        cout << "Enter start position of piece " << choice << " as coordinates (x,y)\n";
                        cin >> old_x >> old_y;
                    }

                    break;
                }
                else if (choice == 'K' || choice == 'Q') {
                    bool pieceFound = false;
                    for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++) {
                            if (board[i][j] == choice) {
                                old_x = i;
                                old_y = j;
                                pieceFound = true;
                                break;
                            }
                        }
                        if (pieceFound) {
                            break;
                        }
                    }
                    if (!pieceFound) {
                        cout << "The piece has been killed by the opponent\n";
                        continue;
                    }

                    break;
                }
                else if (choice == 'N' || choice == 'B') {
                    cout << "Enter start position of piece " << choice << " as (x,y) coordinates\n";
                    cin >> old_x >> old_y;

                    while (old_x < 0 || old_x >= 8 || old_y < 0 || old_y >= 8 || board[old_x][old_y] != choice) {
                        cout << "Invalid position or your desired piece isn't in that location\n";
                        cout << "Please enter again\n";
                        cout << "Enter start position of piece " << choice << " as (x,y) coordinates\n";
                        cin >> old_x >> old_y;
                    }

                    break;
                }
            }

            showValidMoves(board, old_x, old_y);
            cin >> new_x >> new_y;
            if (isValidMove(old_x, old_y, new_x, new_y)) {
                board[new_x][new_y] = board[old_x][old_y];
                board[old_x][old_y] = ' ';
                break;
            }
            else {
                cout << "Invalid move! Try again." << endl;
                continue;

            }


        }

        if(gameOver(board,currentPlayer))
            break;

        currentPlayer=2;

        while (true) {
            printBoard(board);

            cout << "Player "<< currentPlayer<<" (Black)\n ";

            while (true) {
                cout << "Enter name of piece (r,k,q,n,b) you want to move\n";
                cin >> choice;


                if (choice != 'r' && choice != 'k' && choice != 'q' && choice != 'n' && choice != 'b') {
                    cout << "Enter correct name of piece\n";
                    continue;
                }

                if (choice == 'r') {
                    bool pieceFound = false;
                    for(int i = 0; i < 8; i++) {
                        for(int j = 0; j < 8; j++) {
                            if(board[i][j] == choice) {
                                pieceFound = true;
                                break;
                            }
                        }
                        if (pieceFound) {
                            break;
                        }
                    }
                    if (!pieceFound) {
                        cout << "The piece has been killed by the opponent\n";
                        continue;
                    }

                    cout << "Enter start position of piece " << choice << " as (x,y) coordinates\n";
                    cin >> old_x >> old_y;

                    while (old_x < 0 || old_x >= 8 || old_y < 0 || old_y >= 8 || board[old_x][old_y] != choice) {
                        cout << "Invalid position or your desired piece isn't in that location\n";
                        cout << "Please enter again\n";
                        cout << "Enter start position of piece " << choice << " as (x,y) coordinates\n";
                        cin >> old_x >> old_y;
                    }

                    break;
                }
                else if (choice == 'k' || choice == 'q') {
                    bool pieceFound = false;
                    for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++) {
                            if (board[i][j] == choice) {
                                old_x = i;
                                old_y = j;
                                pieceFound = true;
                                break;
                            }
                        }
                        if (pieceFound) {
                            break;
                        }
                    }
                    if (!pieceFound) {
                        cout << "The piece has been killed\n";
                        continue;
                    }

                    break;
                }
                else if (choice == 'n' || choice == 'b') {
                    cout << "Enter start position of piece " << choice << " as (x,y) coordinates\n";
                    cin >> old_x >> old_y;

                    while (old_x < 0 || old_x >= 8 || old_y < 0 || old_y >= 8 || board[old_x][old_y] != choice) {
                        cout << "Invalid position or your desired piece isn't in that location\n";
                        cout << "Please enter again\n";
                        cout << "Enter start position of piece " << choice << " as (x,y) coordinates\n";
                        cin >> old_x >> old_y;
                    }

                    break;
                }
            }
            showValidMoves(board, old_x, old_y);
            cin >> new_x >> new_y;
            if (isValidMove(old_x, old_y, new_x, new_y)) {
                board[new_x][new_y] = board[old_x][old_y];
                board[old_x][old_y] = ' ';
                break;
            }
            else {
                cout << "Invalid move! Try again." << endl;
                continue;

            }


        }

        cout<<endl;

        if(gameOver(board, currentPlayer))
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
