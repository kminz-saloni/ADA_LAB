#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100000; // random number between 0–99999
    }
}


void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid; // Found
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; // Not found
}

int main() {
    // Array sizes to test
    int test_sizes[] = {10, 50, 100, 500, 1000, 3000, 5000, 6000, 7000, 8000};
    int num_tests = sizeof(test_sizes) / sizeof(test_sizes[0]);

    printf("ArraySize,AverageTimeSeconds\n");

    srand(time(NULL)); // Seed for random number generation

    for (int i = 0; i < num_tests; i++) {
        int n = test_sizes[i];

        // Allocate memory for the array
        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("⚠️ Memory allocation failed for n = %d\n", n);
            continue;
        }

        // Prepare data
        generateRandomArray(arr, n);
        bubbleSort(arr, n);

        int target = arr[n - 1]; // Choose last element (worst-case search)

        // Measure binary search time averaged over 10 million runs
        clock_t start = clock();
        for (int j = 0; j < 10000000; j++) {
            binarySearch(arr, n, target);
        }
        clock_t end = clock();

        double avg_time = ((double)(end - start)) / CLOCKS_PER_SEC / 10000000.0;

        // Print results as CSV (easy for plotting)
        printf("%d,%.8f\n", n, avg_time);

        free(arr);
    }

    return 0;
}
