#include <stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void qs(int arr[], int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}


int main()
{
    int n;
    clock_t start,end;
    printf("Enter size of Array: ");
    scanf("%d", &n);

    if (n < 5000)
    {
        printf("Enter elements greater than 5000!");
        return 1;
    }

    int *arr = (int *)malloc(n*sizeof(int));

    srand(time(0));
    for(int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10000;
    }

     start = clock();
      qs(arr, 0, n-1);
     end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken to sort %d elements is: %lf", n, time_taken);
    
    return 0;
}