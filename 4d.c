#include <stdio.h>

// Bottom-up DP
void fib(int n) {
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;

    printf("%d %d ", dp[0], dp[1]);
    for (int i = 2; i < n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
        printf("%d ", dp[i]);
    }
}

int main() {
    int n;
    printf("Karan Minj 044\n");
    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci series: ");
    fib(n);

    return 0;
}
