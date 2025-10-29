#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main() {
    int sizes[] = {1000, 3000, 6000, 10000, 15000, 20000, 25000};
    int testCount = sizeof(sizes) / sizeof(sizes[0]);

    srand(time(NULL));

    for (int i = 0; i < testCount; i++) {
        int n = sizes[i];
        int *arr = (int *)malloc(n * sizeof(int));
        if (!arr) {
            printf("Memory allocation failed for n = %d\n", n);
            continue;
        }

        for (int j = 0; j < n; j++)
            arr[j] = rand();

        clock_t start = clock();
        quickSort(arr, 0, n - 1);
        clock_t end = clock();

        double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Input size: %d | Time taken: %.6f seconds\n", n, timeTaken);

        free(arr);
    }

    return 0;
}
