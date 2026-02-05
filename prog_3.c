#include <stdio.h>
#include <stdlib.h>

//node structure
struct Node {
    int data; //the actual information
    struct Node *link; //the link to next node
};

//function to create node
struct Node* createNode(int value){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value; //assigns value
    newNode->link = NULL; //assigns the link to NULL
    return newNode;
}

//function to insert node at the end
void insert(struct Node ** head, int value){
    struct Node *newNode = createNode(value);

    if(*head == NULL){
        *head = newNode; //if linked list is empty then head points to the newNode now
        return;
    }

    struct Node *temp = *head; // a temporary node
    while(temp -> link != NULL){
        temp = temp->link;
    }
    temp->link = newNode; // the last element now points to the newNode
}

//created a function for reversal traversal
void reverseTraversal(struct Node* head){
    if(head ==NULL){
        return;
    }

    reverseTraversal(head->link); //goes to the end first
    printf("%d ", head->data); //prints while moving down the linked list
}

int main(){
    struct Node *head = NULL;

    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);

    printf("Reverse: \n");
    reverseTraversal(head);

    return 0;
}