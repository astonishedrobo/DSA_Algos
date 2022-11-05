#include<stdio.h>
#include<stdlib.h>

//linked list node
struct Node {
    int data;
    struct Node *next;
} Node;

//insertion sort on linkedlist
void insertionSort(struct Node *head) {
    for(struct Node* temp_i = head; temp_i != NULL; temp_i = temp_i->next) {
        for (struct Node* temp_j = head; temp_j != temp_i; temp_j = temp_j->next) {
            if (temp_i->data < temp_j->data) {
                int temp = temp_i->data;
                temp_i->data = temp_j->data;
                temp_j->data = temp;
            }
        }
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

int main(void) {
    struct Node *head = NULL;
    head = createLL(head);

    printf("Linked list before sorting: ");
    printLL(head);

    //insertion sort on linked list
    insertionSort(head);

    printf("Linked list after sorting: ");
    printLL(head);

    deleteLL(head);
}