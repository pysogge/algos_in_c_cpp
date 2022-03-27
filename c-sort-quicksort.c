#include <stdio.h>

int GLOBAL_RUNS = 0;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_array(int arr[], int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%d,", arr[i]);
    }
    printf("\b]\n");
}

int partition(int arr[], int low, int high){
    // selecting last elem as pivot
    int pivot = arr[high];
    // an index for swapping less than elements to
    // will be the return index for where pivot it
    int i = low;

    for(int j = low; j < high; j++){
        // if current elem is <= pivot
        // swap it with current i index
        // increment i
        if(arr[j] <= pivot){
            swap(&arr[i],&arr[j]);
            i++;
        }
    }
    // swap pivot with i index
    swap(&arr[i],&arr[high]);
    return i;
}

void quicksort(int arr[], int start, int end)
{
    GLOBAL_RUNS++;
    if(start < end){
        int pivot;
        pivot = partition(arr,start,end);
        quicksort(arr,start,pivot-1);
        quicksort(arr,pivot+1,end);
    }

}

int main()
{
    int arr[] = {4, 22, 5, 16, -3, 34, 7, 51, 13, 9, 1, 7, -6, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("before sorting: array size: %d\n", n);
    print_array(arr, n);

    quicksort(arr,0,n-1);

    printf("after sorting: array, runs = %d:\n",GLOBAL_RUNS);
    print_array(arr, n);
}