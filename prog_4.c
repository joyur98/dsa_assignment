#include <stdio.h>
#include <stdlib.h>

//created the Node structure for doubly linked list
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

//function to create new nodes
struct Node* createNode(int value){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

//function to add a node after a given node
void insertAfter(struct Node* prevNode, int value) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }

    struct Node* newNode = createNode(value);

    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if (prevNode->next != NULL){
        prevNode->next->prev = newNode;
    }

    prevNode->next = newNode;
}


//function to delete a node at a position
void deleteNode(struct Node** head, struct Node* delNode){
    if(*head == NULL || delNode == NULL){
        return;
    }

    if(*head == delNode){
        *head = delNode->next;
    }

    if(delNode ->next != NULL){
        delNode->next->prev = delNode->prev;
    }

    if(delNode -> prev != NULL){
        delNode->prev->next = delNode->next;
    }

    free(delNode);
}

// Traversing forward
void print(struct Node* head) {
    struct Node* temp = head;
    printf("List(before): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


//main function where everything is implemented
int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    // creating the nodes
    head = createNode(10);
    second = createNode(20);
    third = createNode(30);

    // linking the nodes
    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    print(head);

    // insert node after 20
    insertAfter(second, 25);
    printf("\nAfter inserting 25 after 20:\n");
    print(head);

    // delete node after 20
    deleteNode(&head, second);
    printf("\nAfter deleting node 20:\n");
    print(head);

    return 0;
}