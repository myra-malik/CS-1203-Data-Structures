#include <stdio.h>
#include <stdbool.h>

// Tower of Hanoi
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    towerOfHanoi(n - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

// Eight Queens
#define N 8

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

bool isSafe(int board[N][N], int row, int col) {
    for (int i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

bool solveNQueens(int board[N][N], int col) {
    if (col >= N) {
        return true;
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;

            if (solveNQueens(board, col + 1)) {
                return true;
            }

            board[i][col] = 0;
        }
    }

    return false;
}

int main() {
    int n = 3; // Number of disks for Tower of Hanoi (you can change this)
    towerOfHanoi(n, 'A', 'B', 'C');
    
    int board[N][N] = {0}; // Initialize the chessboard for Eight Queens

    if (solveNQueens(board, 0)) {
        printf("\nEight Queens Solution:\n");
        printSolution(board);
    } else {
        printf("\nNo Eight Queens solution exists.\n");
    }

    return 0;
}
