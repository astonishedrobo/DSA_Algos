#include <stdio.h>
#include <stdlib.h>

int main(void) {
    //build array of 5 ints in stack
    int arr[5] = {1, 2, 3, 4, 5};

    //build array of 5 ints in heap
    int *heapArr = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        heapArr[i] = i + 1;
    }

    //print out the arrays
    printf("Stack array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    //print out the heap array
    printf("\nHeap array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", heapArr[i]);
    }

    //reallocate the heap array to 10 ints
    heapArr = realloc(heapArr, 10 * sizeof(int));
    for (int i = 5; i < 10; i++) {
        heapArr[i] = i + 1;
    }

    //print out the reallocated heap array
    printf("\nReallocated heap array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", heapArr[i]);
    }
    
    printf("\n");
    
    //free the heap array
    free(heapArr);
}