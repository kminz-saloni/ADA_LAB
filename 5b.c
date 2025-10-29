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
int main() {
int sizes[] = {10, 50, 100, 150};
int numSizes = sizeof(sizes) / sizeof(sizes[0]);
FILE* fp = fopen("zeroone_dp.csv", "w");
if (!fp) { printf("Error opening file\n"); return 1; }
fprintf(fp, "n,time_ms\n");
srand(time(NULL));
for (int i = 0; i < numSizes; i++) {
int n = sizes[i];
int capacity = n * 50;
int* weights = malloc(n * sizeof(int));
int* profits = malloc(n * sizeof(int));
for (int j = 0; j < n; j++) {
weights[j] = rand() % 100 + 1;
profits[j] = rand() % 100 + 1;
}
clock_t start = clock();
int profit = knapsackDP(weights, profits, n, capacity);
clock_t end = clock();
double time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
printf("n=%d profit=%d time=%.2f ms\n", n, profit, time_taken);
fprintf(fp, "%d,%.2f\n", n, time_taken);
free(weights);
free(profits);
}
fclose(fp);
printf("Results saved to zeroone_dp.csv\n");
return 0
