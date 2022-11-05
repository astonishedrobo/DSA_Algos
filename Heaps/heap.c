#include<stdio.h>
#include<stdlib.h>

#define MAX 100
int heap[MAX],n=0;

//insert element into heap
void insert(int x) {
    int i;
    if(n==MAX) {
        printf("\nHeap is full");
        return;
    }
    n++;
    i=n;
    while(i>1 && x<heap[i/2]) {
        heap[i]=heap[i/2];
        i=i/2;
    }
    heap[i]=x;
}

//delete element from heap
int extract_min() {
    int i,child;
    int min,last;

    if(n==0) {
        printf("\nHeap is empty");
        return -1;
    }

    min=heap[1];
    last=heap[n];
    n--;
    i=1;

    while(i*2<=n) {
        child=i*2;
        if(child!=n && heap[child+1]<heap[child])
            child++;
        if(last>heap[child])
            heap[i]=heap[child];
        else
            break;
        i=child;
    }
    heap[i]=last;
    return min;
}

//print heap
void printH()
{
    int i;
    if(n==0) {
        printf("\nHeap is empty");
        return;
    }

    printf("\nHeap is: ");
    for(i=1;i<=n;i++) {
        printf("%d ",heap[i]);
    }
}

int main(void) {
    int ch,x;
    
    while(1) {
        printf("\n\n1.Insert\n2.Extract min\n3.Print\n4.Exit\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch) {
            case 1: printf("\nEnter element to insert: ");
                    scanf("%d",&x);
                    insert(x);
                    break;
            case 2: x=extract_min();
                    printf("\nExtracted element: %d",x);
                    break;
            case 3: printH();
                    break;
            case 4: exit(0);
            default: printf("\nInvalid choice\n");
                    exit(0);
        }
    }
}