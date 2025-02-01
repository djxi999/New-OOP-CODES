#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentMarker;
int currentPlayer;

// Function to display the board
void drawBoard() {
    cout << "Tic Tac Toe Board:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "--|---|--\n";
    }
}

// Function to place a marker on the board
bool placeMarker(int slot) {
    int row = (slot - 1) / 3;  // Row index
    int col = (slot - 1) % 3;  // Column index

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    } else {
        return false;
    }
}

// Function to check for a winner
int checkWinner() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return currentPlayer;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return currentPlayer;
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return currentPlayer;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return currentPlayer;

    return 0; // No winner yet
}

// Main function to play the game
void playGame() {
    cout << "Player 1, choose your marker (X or O): ";
    cin >> currentMarker;
    currentPlayer = 1;

    drawBoard();

    int winner = 0;
    for (int i = 0; i < 9 && winner == 0; i++) {
        int slot;
        cout << "Player " << currentPlayer << ", enter your slot (1-9): ";
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid slot! Try again.\n";
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "Slot already taken! Try again.\n";
            i--;
            continue;
        }

        drawBoard();
        winner = checkWinner();

        // Switch player
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
        currentMarker = (currentMarker == 'X') ? 'O' : 'X';
    }

    if (winner == 0) {
        cout << "It's a tie!\n";
    } else {
        cout << "Player " << winner << " wins!\n";
    }
}

int main() {
    playGame();
    return 0;
}
