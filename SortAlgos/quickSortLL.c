#include<stdio.h>
#include<stdlib.h>

//linked list node
struct Node {
    int data;
    struct Node *next;
};

//partition function for quick sort
struct Node* partition(struct Node* head, struct Node* tail) {

    struct Node* pivot = head;
    struct Node* temp = head;

    int tempData;

    while (temp != tail) {
        if (temp->data < tail->data) {
            pivot = head;

            tempData = temp->data;
            temp->data = pivot->data;
            pivot->data = tempData;

            head = head->next;
        }
        temp = temp->next;
        
    }
    tempData = head->data;
    head->data = tail->data;
    tail->data = tempData;
    return pivot;
    
}

//quick sort on linked list
void quickSort(struct Node* head, struct Node* tail) {
    if (head == tail) {
        return;
    }
    struct Node* pivot = partition(head, tail);
 
    if (pivot != NULL && pivot->next != NULL) {
        quickSort(pivot->next, tail);
    }
 
    if (pivot != NULL && head != pivot) {
        quickSort(head, pivot);
    }
}

//create linked list from user input using scanf
struct Node* createLL(struct Node* head) {
    struct Node *temp = NULL;
    
    int data;
    printf("Enter -1 to stop data entry\n");
    printf("Enter data: ");
    scanf("%d", &data);
    while (data != -1) {
        if (head == NULL) {
            head = (struct Node *)malloc(sizeof(struct Node));
            head->data = data;
            head->next = NULL;
            temp = head;
        } else {
            temp->next = (struct Node *)malloc(sizeof(struct Node));
            temp = temp->next;
            temp->data = data;
            temp->next = NULL;
        }
        printf("Enter data: ");
        scanf("%d", &data);
    }
    printf("\n");
    return head;
}

//print linked list
void printLL(struct Node* head) {
    struct Node* temp = head;
    
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//delete linked list
void deleteLL(struct Node* head) {
    struct Node* temp = head;
    struct Node* temp2 = NULL;
    
    while(temp != NULL) {
        temp2 = temp;
        temp = temp->next;
        free(temp2);
    }
}

int lengthLL(struct Node* head) {
    struct Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main(void) {
    
    struct Node *head = NULL;
    head = createLL(head);

    //quit if length of linked list is 0
    int lenLL = lengthLL(head);
    if (lenLL <= 0) {
        printf("Linked list is empty\n");
        return 0;
    }

    //find tail of linked list
    struct Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    //call quick sort
    quickSort(head, tail);
    
    //print sorted linked list
    printf("\nSorted linked list: ");
    printLL(head);

    deleteLL(head);
}