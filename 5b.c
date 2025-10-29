#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int max(int a, int b) { return (a > b) ? a : b; }
int knapsackDP(int weights[], int profits[], int n, int capacity) {
int** dp = malloc((n + 1) * sizeof(int*));
for (int i = 0; i <= n; i++)
dp[i] = calloc(capacity + 1, sizeof(int));
for (int i = 1; i <= n; i++) {
for (int w = 0; w <= capacity; w++) {
if (weights[i - 1] <= w)
dp[i][w] = max(profits[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
else
dp[i][w] = dp[i - 1][w];
}
}
int res = dp[n][capacity];
for (int i = 0; i <= n; i++) free(dp[i]);
free(dp);
return res;
}
