#include<stdio.h>
#include<stdlib.h>

//liked list node
struct Node
{
    int data;
    struct Node *next;
};

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

//print half linked list
void printHalfLL(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        printf("%d ", slow->data);
        slow = slow->next;
        fast = fast->next->next;
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
    printf("First half of linked list: ");
    printHalfLL(head);
    deleteLL(head);
}