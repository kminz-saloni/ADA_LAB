#include <time.h>
typedef struct {
int profit, weight;
float ratio;
} Item;
int compare(const void* a, const void* b) {
Item* i1 = (Item*)a;
Item* i2 = (Item*)b;
if (i2->ratio > i1->ratio) return 1;
else if (i2->ratio < i1->ratio) return -1;
else return 0;
}
int knapsackGreedy(Item items[], int n, int capacity) {
qsort(items, n, sizeof(Item), compare);
int totalProfit = 0;
for (int i = 0; i < n && capacity > 0; i++) {
if (items[i].weight <= capacity) {
capacity -= items[i].weight;
totalProfit += items[i].profit;
}
}
return totalProfit;
}
int main() {
int sizes[] = {10, 50, 100, 150, 200};
int numSizes = sizeof(sizes) / sizeof(sizes[0]);
FILE* fp = fopen("zeroone_greedy.csv", "w");
if (!fp) {
printf("Error opening file\n");
return 1;
}
fprintf(fp, "n,time_ms\n");
srand(time(NULL));
for (int i = 0; i < numSizes; i++) {
int n = sizes[i];
int capacity = n * 50;
Item* items = malloc(n * sizeof(Item));
for (int j = 0; j < n; j++) {
items[j].weight = rand() % 100 + 1;
items[j].profit = rand() % 100 + 1;
items[j].ratio = (float)items[j].profit / items[j].weight;
}
clock_t start = clock();
int profit = knapsackGreedy(items, n, capacity);
clock_t end = clock();
double time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
printf("n=%d profit=%d time=%.2f ms\n", n, profit, time_taken);
fprintf(fp, "%d,%.2f\n", n, time_taken);
free(items);
}
fclose(fp);
printf("Results saved to zeroone_greedy.csv\n"
return;
}
