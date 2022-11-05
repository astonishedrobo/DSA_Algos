#include<stdio.h>
#include<stdlib.h>

//swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//partition function for quick sort
int partition(int left, int right, int arr[]) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[right]);
    return i+1;
}

//quick sort on array of integers
void quickSort(int left, int right, int arr[]) {
    if (left < right) {
        int pivot = partition(left, right, arr);
        quickSort(left, pivot-1, arr);
        quickSort(pivot+1, right, arr);
    }
}

int main(void) {
    
    //define array size from user input
    int N=0;
    printf("Enter number of elements: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Invalid array size\n");
        return 0;
    }

    //allocate memory for array
    int *arr = (int *) malloc(N * sizeof(int));

    //take array input from user
    for (int i=0; i<N; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("\n");

    //quick sort
    quickSort(0, N-1, arr);

    //printing sorted array
    printf("Sorted array: ");
    for(int i=0; i<N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}