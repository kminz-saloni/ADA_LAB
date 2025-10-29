#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Linear Search Function
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1; // Not found
}

int main(void) {
    int n = 100000;        // Number of elements to search
    int repeat = 100;      // Number of times to repeat the search
    int *arr;
    int key, pos;
    clock_t start, end;
    double elapsed = 0.0;

    // Dynamically allocate array
    if ((arr = malloc(n * sizeof(int))) == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Seed random generator and fill array with random values
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (n * 2);
    }

    // Randomly select an element to search
    key = arr[rand() % n];

    // Measure search time by repeating the search
    start = clock();
    for (int i = 0; i < repeat; i++) {
        pos = linearSearch(arr, n, key);
    }
    end = clock();

    elapsed = (double)(end - start) / CLOCKS_PER_SEC / repeat;

    if (pos >= 0) {
        printf("Element %d found at index %d\n", key, pos);
    } else {
        printf("Element %d not found\n", key);
    }

    printf("Average search time: %lf seconds\n", elapsed);

    free(arr);
    return 0;
}
