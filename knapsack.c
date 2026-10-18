#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }

void knapsack(int wt[], int val[], int n, int W) {
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    printf("Maximum Profit = %d\nSelected Items: ", dp[n][W]);
    for (int i = n, w = W; i > 0 && dp[i][w] > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            printf("Item %d ", i);
            w -= wt[i - 1];
        }
    }
    printf("\n");
}

int main() {
    int wt[] = {2, 3, 4, 5}, val[] = {3, 4, 5, 6}, n = 4, W = 5;
    knapsack(wt, val, n, W);
    return 0;
}
