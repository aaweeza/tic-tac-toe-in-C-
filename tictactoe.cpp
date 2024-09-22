#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char currentMarker;
int currentPlayer;

void clearConsole() {
        system("cls");  // For Windows
}

void drawBoard() {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    } else {
        return false;
    }
}

int checkWinner() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return currentPlayer;
        }
    }
    
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return currentPlayer;
        }
    }
    
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return currentPlayer;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return currentPlayer;
    }
    
    return 0;
}

void swapPlayerAndMarker() {
    if (currentMarker == 'X') {
        currentMarker = 'O';
    } else {
        currentMarker = 'X';
    }

    if (currentPlayer == 1) {
        currentPlayer = 2;
    } else {
        currentPlayer = 1;
    }
}

void game() {
    cout << "Player 1, choose your marker (X or O): ";
    char markerP1;
    cin >> markerP1;

    currentPlayer = 1;
    currentMarker = markerP1;

    drawBoard();
    
    int winner = 0;
    for (int i = 0; i < 9; i++) {
        cout << "It's player " << currentPlayer << "'s turn. Enter your slot: ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "That is not a valid slot! Try again." << endl;
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "That slot is occupied! Try again." << endl;
            i--;
            continue;
        }

        drawBoard();

        winner = checkWinner();
        if (winner == 1) {
            cout << "Player 1 wins!" << endl;
            break;
        } else if (winner == 2) {
            cout << "Player 2 wins!" << endl;
            break;
        }

        swapPlayerAndMarker();
    }

    if (winner == 0) {
        cout << "It's a tie!" << endl;
    }
}

int main() {
		system("color 3f");
    // Welcome message
    cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tWELCOME :)\n";
    this_thread::sleep_for(chrono::seconds(4));
    clearConsole();

    // Loading animation
    for (int i = 1; i <= 100; ++i) {
        this_thread::sleep_for(chrono::milliseconds(50));  // Adjust the sleep duration as needed
        clearConsole();
        cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\tTIC TAC TOE\n\t\t\tBY AAWEEZA FAROOQUI" << endl;
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tLOADING " << i << "%";
    }
    
    this_thread::sleep_for(chrono::seconds(1));

    // Start the game
    clearConsole();
    game();
    
    return 0;
}
