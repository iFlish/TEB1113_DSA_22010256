
/*
Student ID:22010256
Lab Group: 3


*/

// This program checks if a Tic-Tac-Toe board state is valid.

#include <iostream>
using namespace std;

int winningPatterns[8][3] = {
    {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
    {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
    {0, 4, 8}, {2, 4, 6}
};

bool isWinner(char* boardState, char player) {
    for (int i = 0; i < 8; i++)
        if (boardState[winningPatterns[i][0]] == player &&
            boardState[winningPatterns[i][1]] == player &&
            boardState[winningPatterns[i][2]] == player)
            return true;
    return false;
}

bool isBoardValid(char boardState[9]) {
    int totalX = 0, totalO = 0;
    for (int i = 0; i < 9; i++) {
        if (boardState[i] == 'X') totalX++;
        if (boardState[i] == 'O') totalO++;
    }

    if (totalX == totalO || totalX == totalO + 1) {
        if (isWinner(boardState, 'O')) {
            if (isWinner(boardState, 'X'))
                return false;
            return (totalX == totalO);
        }
        if (isWinner(boardState, 'X') && totalX != totalO + 1)
            return false;
        return true;
    }
    return false;
}

int main() {
    char boardState[] = {'X', 'X', 'O',
                         'O', 'O', 'X',
                         'X', 'O', 'X'};
    isBoardValid(boardState) ? cout << "Given board is valid"
                              : cout << "Given board is not valid";
    return 0;
}
