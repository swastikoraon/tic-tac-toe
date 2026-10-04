#include <iostream>
using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

// Display the game board
void displayBoard() {
    cout << "\n";
    cout << "-------------\n";

    for (int i = 0; i < 3; i++) {
        cout << "| ";

        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }

        cout << "\n-------------\n";
    }
}

// Check whether a player has won
bool checkWin(char player) {

    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player &&
            board[1][j] == player &&
            board[2][j] == player) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player) {
        return true;
    }

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player) {
        return true;
    }

    return false;
}

// Check whether the board is full
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }

    return true;
}

// Make a player's move
void makeMove(char player) {

    int position;

    while (true) {

        cout << "Player " << player << ", enter position (1-9): ";
        cin >> position;

        if (position < 1 || position > 9) {
            cout << "Invalid position! Try again.\n";
            continue;
        }

        int row = (position - 1) / 3;
        int column = (position - 1) % 3;

        if (board[row][column] == 'X' ||
            board[row][column] == 'O') {

            cout << "Position already occupied! Try again.\n";
            continue;
        }

        board[row][column] = player;
        break;
    }
}

int main() {

    char currentPlayer = 'X';

    cout << "=================================\n";
    cout << "        TIC TAC TOE GAME\n";
    cout << "=================================\n";

    cout << "\nPlayer X vs Player O\n";
    cout << "Enter the number of the position you want to play.\n";

    while (true) {

        displayBoard();

        makeMove(currentPlayer);

        // Check winner
        if (checkWin(currentPlayer)) {

            displayBoard();

            cout << "\n=================================\n";
            cout << " Player " << currentPlayer << " WINS!\n";
            cout << "=================================\n";

            break;
        }

        // Check draw
        if (checkDraw()) {

            displayBoard();

            cout << "\n=================================\n";
            cout << "          GAME DRAW!\n";
            cout << "=================================\n";

            break;
        }

        // Change player
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        }
        else {
            currentPlayer = 'X';
        }
    }

    cout << "\nThank you for playing!\n";

    return 0;
}