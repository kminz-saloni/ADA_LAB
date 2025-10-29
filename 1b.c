#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Binary Search Function
int binarySearch(int arr[], int l, int r, int key) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

// Comparison Function for qsort
int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }

    int key;
    printf("Enter key to search: ");
    scanf("%d", &key);

    // Sort array before binary search
    qsort(arr, n, sizeof(int), cmpfunc);

    clock_t start, end;
    double time_taken;

    start = clock();
    int result = binarySearch(arr, 0, n - 1, key);
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("T = %d, Time taken = %.6f seconds\n", n, time_taken);

    free(arr);
    return 0;
}
