#include<stdio.h>
#include<stdlib.h>

//Linked list node
struct Node {
    int data;
    struct Node* next;
};

//function to create linked list from user input which returns head pointer after creating linked list
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
    struct Node* head = NULL;
    head = createLL(head);

    for(struct Node* temp_i = head; temp_i != NULL; temp_i=temp_i->next) {
        struct Node* smallest = temp_i;
        for(struct Node* temp_j = temp_i->next; temp_j != NULL; temp_j=temp_j->next) {
            if (smallest->data > temp_j->data) {
                smallest = temp_j;
            }
        }
        //swap node values
        int i_val = temp_i->data;
        temp_i->data = smallest->data;
        smallest->data = i_val;

    }
    printf("Sorted linked list: ");
    printLL(head);
    deleteLL(head);
}