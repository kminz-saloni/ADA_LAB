#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform Linear Search
int linearSearch(int array[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (array[i] == target)
            return i;  // Found the element, return its index
    }
    return -1; // Not found
}

int main() {
    int size, target;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    // Allocate memory dynamically for the array
    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Error: Memory allocation failed!\n");
        return 1;
    }

    // Seed random number generator
    srand(time(NULL));

    // Generate a random array
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100000; // random number between 0 and 99999
    }

    // Choose the last element as the search target (worst-case scenario)
    target = array[size - 1];

    // Measure execution time for 1000 runs to get an average
    clock_t start = clock();

    for (int i = 0; i < 1000; i++) {
        int result = linearSearch(array, size, target);
        (void)result; // suppress unused variable warning
    }

    clock_t end = clock();

    // Calculate average time per search
    double avg_time = ((double)(end - start)) / CLOCKS_PER_SEC / 1000.0;

    printf("\nElement searched: %d\n", target);
    printf("Average time taken for n = %d: %f seconds per search (over 1000 runs)\n", size, avg_time);

    // Free allocated memory
    free(array);

    return 0;
}
