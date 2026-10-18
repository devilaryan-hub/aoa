#include <stdio.h>
#define MAX 20

int board[MAX][MAX], n;

int isSafe(int r, int c) {
    for (int i = 0; i < r; i++) {
        if (board[i][c]) return 0;
        if (c - (r - i) >= 0 && board[i][c - (r - i)]) return 0;
        if (c + (r - i) < n && board[i][c + (r - i)]) return 0;
    }
    return 1;
}

int solve(int r) {
    if (r == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) printf("%c ", board[i][j] ? 'Q' : '.');
            printf("\n");
        }
        return 1;
    }
    for (int c = 0; c < n; c++) {
        if (isSafe(r, c)) {
            board[r][c] = 1;
            if (solve(r + 1)) return 1;
            board[r][c] = 0;
        }
    }
    return 0;
}

int main() {
    n = 4;
    if (!solve(0)) printf("No solution\n");
    return 0;
}
