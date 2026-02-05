#include <stdio.h>
#include <stdlib.h>

//node structure
struct Node {
    int data; //the actual information
    struct Node *link; //the link to next node
};

struct Node* createNode(int value){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->link = NULL;
    return newNode;
}

void insert(struct Node ** head, int value){
    struct Node *newNode = createNode(value);

    if(*head == NULL){
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while(temp -> link != NULL){
        temp = temp->link;
    }
    temp->link = newNode;
}