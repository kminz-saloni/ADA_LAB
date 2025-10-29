#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Utility functions
void fillMatrix(int n, int **mat) {
for (int i = 0; i < n; i++)
for (int j = 0; j < n; j++)
mat[i][j] = rand() % 10;
}
void add(int n, int **A, int **B, int **result) {
for (int i = 0; i < n; i++)
for (int j = 0; j < n; j++)
result[i][j] = A[i][j] + B[i][j];
}
void subtract(int n, int **A, int **B, int **result) {
for (int i = 0; i < n; i++)
for (int j = 0; j < n; j++)
result[i][j] = A[i][j] - B[i][j];
}
void multiplyStrassen(int n, int **A, int **B, int **C) {
if (n == 1) {
C[0][0] = A[0][0] * B[0][0];
return;
}
int newSize = n / 2;
// Allocate submatrices
int **A11 = malloc(newSize * sizeof(int *));
int **A12 = malloc(newSize * sizeof(int *));
int **A21 = malloc(newSize * sizeof(int *));
int **A22 = malloc(newSize * sizeof(int *));
int **B11 = malloc(newSize * sizeof(int *));
int **B12 = malloc(newSize * sizeof(int *));
int **B21 = malloc(newSize * sizeof(int *));
int **B22 = malloc(newSize * sizeof(int *));
int **M1 = malloc(newSize * sizeof(int *));
int **M2 = malloc(newSize * sizeof(int *));
int **M3 = malloc(newSize * sizeof(int *));
int **M4 = malloc(newSize * sizeof(int *));
int **M5 = malloc(newSize * sizeof(int *));
nt **M6 = malloc(newSize * sizeof(int *));
int **M7 = malloc(newSize * sizeof(int *));
int **AResult = malloc(newSize * sizeof(int *));
int **BResult = malloc(newSize * sizeof(int *));
int **C11 = malloc(newSize * sizeof(int *));
int **C12 = malloc(newSize * sizeof(int *));
int **C21 = malloc(newSize * sizeof(int *));
int **C22 = malloc(newSize * sizeof(int *));
for (int i = 0; i < newSize; i++) {
A11[i] = malloc(newSize * sizeof(int));
A12[i] = malloc(newSize * sizeof(int));
A21[i] = malloc(newSize * sizeof(int));
A22[i] = malloc(newSize * sizeof(int));
B11[i] = malloc(newSize * sizeof(int));
B12[i] = malloc(newSize * sizeof(int));
B21[i] = malloc(newSize * sizeof(int));
B22[i] = malloc(newSize * sizeof(int));
M1[i] = malloc(newSize * sizeof(int));
M2[i] = malloc(newSize * sizeof(int));
M3[i] = malloc(newSize * sizeof(int));
M4[i] = malloc(newSize * sizeof(int));
M5[i] = malloc(newSize * sizeof(int));
M6[i] = malloc(newSize * sizeof(int));
M7[i] = malloc(newSize * sizeof(int));
AResult[i] = malloc(newSize * sizeof(int));
BResult[i] = malloc(newSize * sizeof(int));
C11[i] = malloc(newSize * sizeof(int));
C12[i] = malloc(newSize * sizeof(int));
C21[i] = malloc(newSize * sizeof(int));
C22[i] = malloc(newSize * sizeof(int));
}
// Divide matrices
for (int i = 0; i < newSize; i++)
for (int j = 0; j < newSize; j++) {
A11[i][j] = A[i][j];
A12[i][j] = A[i][j + newSize];
A21[i][j] = A[i + newSize][j];
A22[i][j] = A[i + newSize][j + newSize];
B11[i][j] = B[i][j];
B12[i][j] = B[i][j + newSize];
B21[i][j] = B[i + newSize][j];
B22[i][j] = B[i + newSize][j + newSize];
}
// M1 = (A11 + A22) * (B11 + B22)
add(newSize, A11, A22, AResult);
add(newSize, B11, B22, BResult);
multiplyStrassen(newSize, AResult, BResult, M1);
// M2 = (A21 + A22) * B1
add(newSize, A21, A22, AResult);
multiplyStrassen(newSize, AResult, B11, M2);
// M3 = A11 * (B12 - B22)
subtract(newSize, B12, B22, BResult);
multiplyStrassen(newSize, A11, BResult, M3);
// M4 = A22 * (B21 - B11)
subtract(newSize, B21, B11, BResult);
multiplyStrassen(newSize, A22, BResult, M4);
// M5 = (A11 + A12) * B22
add(newSize, A11, A12, AResult);
multiplyStrassen(newSize, AResult, B22, M5);
// M6 = (A21 - A11) * (B11 + B12)
subtract(newSize, A21, A11, AResult);
add(newSize, B11, B12, BResult);
multiplyStrassen(newSize, AResult, BResult, M6);
// M7 = (A12 - A22) * (B21 + B22)
subtract(newSize, A12, A22, AResult);
add(newSize, B21, B22, BResult);
multiplyStrassen(newSize, AResult, BResult, M7);
// C11 = M1 + M4 - M5 + M7
add(newSize, M1, M4, AResult);
subtract(newSize, AResult, M5, BResult);
add(newSize, BResult, M7, C11);
// C12 = M3 + M5
add(newSize, M3, M5, C12);
// C21 = M2 + M4
add(newSize, M2, M4, C21);
// C22 = M1 - M2 + M3 + M6
subtract(newSize, M1, M2, AResult);
add(newSize, AResult, M3, BResult);
add(newSize, BResult, M6, C22);
// Combine into result matrix C
for (int i = 0; i < newSize; i++)
for (int j = 0; j < newSize; j++) {
C[i][j] = C11[i][j];
C[i][j + newSize] = C12[i][j];
C[i + newSize][j] = C21[i][j];
C[i + newSize][j + newSize] = C22[i][j];
}
// Free allocated memory
33 | P a g e
for (int i = 0; i < newSize; i++) {
free(A11[i]); free(A12[i]); free(A21[i]); free(A22[i]);
free(B11[i]); free(B12[i]); free(B21[i]); free(B22[i]);
free(M1[i]); free(M2[i]); free(M3[i]); free(M4[i]);
free(M5[i]); free(M6[i]); free(M7[i]);
free(AResult[i]); free(BResult[i]);
free(C11[i]); free(C12[i]); free(C21[i]); free(C22[i]);
}
free(A11); free(A12); free(A21); free(A22);
free(B11); free(B12); free(B21); free(B22);
free(M1); free(M2); free(M3); free(M4);
free(M5); free(M6); free(M7);
free(AResult); free(BResult);
free(C11); free(C12); free(C21); free(C22);
}
int main() {
srand(time(NULL));
FILE *file = fopen("strassen_times.csv", "w");
if (!file) {
printf("Unable to open file for writing.\n");
return 1;
}
fprintf(file, "Size,Time\n");
int sizes[] = {8,16, 32, 64, 128, 256, 512};
int numSizes = sizeof(sizes) / sizeof(sizes[0]);
printf("Strassen's Matrix Multiplication\n");
printf("Size\tTime (seconds)\n");
for (int s = 0; s < numSizes; s++) {
int n = sizes[s];
// Allocate matrices
int **A = malloc(n * sizeof(int *));
int **B = malloc(n * sizeof(int *));
int **C = malloc(n * sizeof(int *));
for (int i = 0; i < n; i++) {
A[i] = malloc(n * sizeof(int));
B[i] = malloc(n * sizeof(int));
C[i] = malloc(n * sizeof(int));
}
fillMatrix(n, A);
fillMatrix(n, B);
clock_t start = clock();
multiplyStrassen(n, A, B, C);
clock_t end = clock();
double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
fprintf(file, "%d,%f\n", n, timeTaken);
printf("%d\t%f\n", n, timeTaken);
for (int i = 0; i < n; i++) {
free(A[i]);
free(B[i]);
free(C[i]);
}
free(A);
free(B);
free(C);
}
fclose(file);
return 0;
