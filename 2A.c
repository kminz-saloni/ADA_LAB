#include <stdio.h>
#include <stdlib.h>

// Function to multiply two 2x2 matrices using Strassen's algorithm
void multiply2x2(int A[2][2], int B[2][2], int C[2][2]) {
    int a00 = A[0][0], a01 = A[0][1], a10 = A[1][0], a11 = A[1][1];
    int b00 = B[0][0], b01 = B[0][1], b10 = B[1][0], b11 = B[1][1];

    // Strassen's products
    int P1 = (a00 + a11) * (b00 + b11);
    int P2 = (a10 + a11) * b00;
    int P3 = a00 * (b01 - b11);
    int P4 = a11 * (b10 - b00);
    int P5 = (a00 + a01) * b11;
    int P6 = (a10 - a00) * (b00 + b01);
    int P7 = (a01 - a11) * (b10 + b11);

    // Combine into C
    C[0][0] = P1 + P4 - P5 + P7;
    C[0][1] = P3 + P5;
    C[1][0] = P2 + P4;
    C[1][1] = P1 + P3 - P2 + P6;
}

// Function to add two 2x2 matrices
void add2x2(int A[2][2], int B[2][2], int C[2][2]) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Function to multiply two 4x4 matrices using divide and conquer
void multiply4x4(int A[4][4], int B[4][4], int C[4][4]) {
    // Divide A into 2x2 submatrices
    int A11[2][2], A12[2][2], A21[2][2], A22[2][2];
    int B11[2][2], B12[2][2], B21[2][2], B22[2][2];
    int C11[2][2], C12[2][2], C21[2][2], C22[2][2];
    int temp1[2][2], temp2[2][2];

    printf("Step 1: Dividing matrices into 2x2 submatrices\n");

    // Fill submatrices
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+2];
            A21[i][j] = A[i+2][j];
            A22[i][j] = A[i+2][j+2];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+2];
            B21[i][j] = B[i+2][j];
            B22[i][j] = B[i+2][j+2];
        }
    }

    printf("A11:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) printf("%d ", A11[i][j]);
        printf("\n");
    }
    // Similarly for others, but to keep it short, maybe just mention

    printf("Step 2: Computing C11 = A11*B11 + A12*B21\n");
    multiply2x2(A11, B11, temp1);
    multiply2x2(A12, B21, temp2);
    add2x2(temp1, temp2, C11);

    printf("Step 3: Computing C12 = A11*B12 + A12*B22\n");
    multiply2x2(A11, B12, temp1);
    multiply2x2(A12, B22, temp2);
    add2x2(temp1, temp2, C12);

    printf("Step 4: Computing C21 = A21*B11 + A22*B21\n");
    multiply2x2(A21, B11, temp1);
    multiply2x2(A22, B21, temp2);
    add2x2(temp1, temp2, C21);

    printf("Step 5: Computing C22 = A21*B12 + A22*B22\n");
    multiply2x2(A21, B12, temp1);
    multiply2x2(A22, B22, temp2);
    add2x2(temp1, temp2, C22);

    printf("Step 6: Combining submatrices into result matrix\n");

    // Fill the result matrix C
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = C11[i][j];
            C[i][j+2] = C12[i][j];
            C[i+2][j] = C21[i][j];
            C[i+2][j+2] = C22[i][j];
        }
    }
}

int main() {
    int A[4][4], B[4][4], C[4][4];

    printf("Enter elements of matrix A (4x4):\n");
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of matrix B (4x4):\n");
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            scanf("%d", &B[i][j]);

    multiply4x4(A, B, C);

    printf("Resultant matrix C:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}
