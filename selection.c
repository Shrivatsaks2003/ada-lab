#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n, i;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of elements (n): ");
    scanf("%d", &n);

    if (n < 5000) {
        printf("Please enter a value of n greater than 5000.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));

    // Generate n random numbers based on my computer time 
    srand(time(NULL));
    // printf("Randomly generated array: ");
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // Generating random numbers between 0 to 9999
        // printf("%d ", arr[i]);
    }
    // printf("\n");

    // Record the starting time
    start = clock();

    // Perform Selection Sort
    selectionSort(arr, n);

    // Record the ending time
    end = clock();

    // Calculate the time taken
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    // printf("Sorted array: ");
    // for (i = 0; i < n; i++) {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");

    printf("Time taken for sorting: %lf seconds\n", cpu_time_used);

    free(arr); // Free dynamically allocated memory
    return 0;
}
