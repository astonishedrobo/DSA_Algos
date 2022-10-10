#include<stdio.h>
#include<stdlib.h>

//selection sort on array of integers
void selectionSort(int arr[], int N) {
    for(int i=0; i<N; i++) {
        int smallest = arr[i];
        int smallestIndex = i;
        
        //find smallest element in unsorted array
        for(int j=i+1; j<N; j++) {
            if (arr[j] < smallest) {
                smallest = arr[j];
                smallestIndex = j;
            }
        }
        //swap
        int temp = arr[i];
        arr[i] = smallest;
        arr[smallestIndex] = temp;
        
    }
}


int main(void) {

    //define array size from user input
    int N=0;
    printf("Enter number of elements: ");
    scanf("%d", &N);

    int *arr = (int *) malloc(N * sizeof(int));

    //take array input from user
    for (int i=0; i<N; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("\n");

    //selection sort
    selectionSort(arr, N);

    //print sorted array
    printf("Sorted array: ");
    for (int i=0; i<N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}