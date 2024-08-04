#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int low, int mid, int high)
{
    int i, j, k, B[high+1];

    i = low;
    j = mid + 1;
    k = low;

    while(i <= mid && j <= high)
    {
        if(arr[i] < arr[j])
        {
            B[k] = arr[i];
            i++;
            k++; 
        }
        else
        {
            B[k] = arr[j];
            j++;
            k++;
        }
    }

    while(i <= mid)
    {
        B[k] = arr[i];
        i++;
        k++;
    }

    while(j <= high)
    {
        B[k] = arr[j];
        j++;
        k++;
    }

    for(i = low; i <= high; i++)
    {
        arr[i] = B[i];
    }

}

void mergeSort(int arr[], int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
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
    mergeSort(arr, 0, n-1);
     end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken to sort %d elements is: %lf", n, time_taken);
    
    return 0;
}