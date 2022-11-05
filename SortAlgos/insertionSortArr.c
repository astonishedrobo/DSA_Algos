#include<stdio.h>
#include<stdlib.h>

//insertion sort on array of integers
void insertionSort(int arr[], int n) {
    int j, key;
    for (int i=0; i<n; i++) {
        key = arr[i];
        j = i-1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
    int *arr = (int *) malloc(N * sizeof(int));

    //take array input from user
    for (int i=0; i<N; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("\n");

    insertionSort(arr, N);

    //printing sorted array
    printf("Sorted array: ");
    for(int i=0; i<N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}