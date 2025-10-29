#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Modified insertion sort function
void sortByInsertion(int dataset[], int length) {
    for (int pos = 1; pos < length; pos++) {
        int temp = dataset[pos];
        int index = pos - 1;
        while (index >= 0 && dataset[index] > temp) {
            dataset[index + 1] = dataset[index];
            index--;
        }
        dataset[index + 1] = temp;
    }
}

int main() {
    int test_sizes[] = {100, 300, 600, 900, 1200, 1500, 1800};
    int test_count = sizeof(test_sizes) / sizeof(test_sizes[0]);
    srand(time(NULL));

    for (int k = 0; k < test_count; k++) {
        int length = test_sizes[k];
        int *dataset = (int*) malloc(length * sizeof(int));
        // Initialize random data
        for (int m = 0; m < length; m++) {
            dataset[m] = rand();
        }

        clock_t begin = clock();
        sortByInsertion(dataset, length);
        clock_t finish = clock();

        double duration = (double)(finish - begin) / CLOCKS_PER_SEC;
        printf("Array size: %d, Duration: %lf seconds\n", length, duration);
        free(dataset);
    }
    return 0;
}
