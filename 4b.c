#include <stdio.h>

// Iterative Fibonacci
void fib(int n) {
    int a = 0, b = 1, next;
    for (int i = 0; i < n; i++) {
        if (i <= 1)
            next = i;
        else {
            next = a + b;
            a = b;
            b = next;
        }
        printf("%d ", next);
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
