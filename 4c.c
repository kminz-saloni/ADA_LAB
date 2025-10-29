#include <stdio.h>

int dp[1000]; // memoization array

int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (dp[n] != -1) return dp[n];

    dp[n] = fib(n - 1) + fib(n - 2);
    return dp[n];
}

int main() {
    int n;
    printf("Karan Minj 044\n");
    printf("Enter number of terms: ");
    scanf("%d", &n);

    // initialize dp with -1
    for (int i = 0; i < 1000; i++) dp[i] = -1;

    printf("Fibonacci series: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", fib(i));
    }
    return 0;
}
