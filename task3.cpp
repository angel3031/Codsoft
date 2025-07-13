#include <iostream>
using namespace std;


char board[3][3];            
char currentPlayer;          


void setupBoard() {
    char position = '1';
    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 3; col++) {
            board[row][col] = position++;
        }
    }
}


void showBoard() {
    cout << "\nCurrent Board:\n\n";
    for(int row = 0; row < 3; row++) {
        cout << " ";
        for(int col = 0; col < 3; col++) {
            cout << board[row][col];
            if(col < 2) cout << " | ";
        }
        if(row < 2) cout << "\n-----------\n";
    }
    cout << "\n\n";
}


void changeTurn() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}


bool placeMark(int cell) {
    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;

    
    if(cell < 1 || cell > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        return false;
    }

    board[row][col] = currentPlayer; 
    return true;
}


bool hasPlayerWon() {
    for(int i = 0; i < 3; i++) {
        
        if((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
           (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer))
            return true;
    }

    
    if((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
       (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer))
        return true;

    return false;
}


bool isBoardFull() {
    for(int row = 0; row < 3; row++)
        for(int col = 0; col < 3; col++)
            if(board[row][col] != 'X' && board[row][col] != 'O')
                return false;
    return true;
}

int main() {
    char playAgain;

    do {
        setupBoard();        
        currentPlayer = 'X'; 
        bool gameOver = false;

        cout << "🎮 Welcome to Tic-Tac-Toe for Two Players! 🎮\n";

        while(!gameOver) {
            showBoard();
            int move;

            cout << "Player " << currentPlayer << ", choose a cell (1-9): ";
            cin >> move;

            if(placeMark(move)) {
                if(hasPlayerWon()) {
                    showBoard();
                    cout << " Congratulations! Player " << currentPlayer << " wins!\n";
                    gameOver = true;
                } else if(isBoardFull()) {
                    showBoard();
                    cout << " It's a draw! Well played both.\n";
                    gameOver = true;
                } else {
                    changeTurn(); 
                }
            } else {
                cout << " Invalid move! That spot is taken or out of range. Try again.\n";
            }
        }

        cout << " Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while(playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! Goodbye!\n";
    return 0;
}
