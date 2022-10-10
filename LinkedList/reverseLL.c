#include<stdio.h>
#include<stdlib.h>

//Linked list node
struct Node {
    int data;
    struct Node* next;
};

//Function to create linked list from user input which returns head pointer after creating linked list
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

//iterative function to reverse linked list
struct Node* reverseLL(struct Node* head) {
    struct Node* temp = head;
    struct Node* prev = NULL;
    struct Node* next = NULL;

    while(temp != NULL) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
    return head;
}

//function to print linked list
void printLL(struct Node* head) {
    struct Node* temp = head;
    
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
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
    printLL(head);
    printf("\n");
    head = reverseLL(head);
    printLL(head);
    printf("\n");
    deleteLL(head);
}