# Program Documentation: Reverse Traversal of Linked List

---

## (a) Explanation of data structures

The program uses a singly linked list implemented using a `struct`.

- `struct Node`  
  Represents each node of the linked list with two fields:
  - `int data;` -> stores the actual information of the node
  - `struct Node *link;` -> points to the next node in the list or NULL if it is the last node

The linked list allows dynamic memory allocation and traversal in a sequential manner.  
- The `head` pointer points to the first node of the list.  
- Nodes are connected through the `link` pointer.  

---

## (b) Description of functions

### `struct Node* createNode(int value)`
- **Purpose:** Creates a new node with the given value.
- **Logic:**  
  - Allocates memory for a new node.
  - Assigns `value` to `data`.
  - Sets `link` to `NULL`.
  - Returns pointer to the new node.

---

### `void insert(struct Node **head, int value)`
- **Purpose:** Inserts a new node at the end of the linked list.
- **Logic:**  
  1. Creates a new node using `createNode()`.
  2. If the list is empty (`*head == NULL`) -> `head` points to the new node.
  3. Otherwise, traverses the list until the last node.
  4. Sets the `link` of the last node to the new node.

---

### `void reverseTraversal(struct Node* head)`
- **Purpose:** Prints the linked list in reverse order without modifying it.
- **Logic:**  
  1. Recursively traverses to the end of the list.
  2. Prints `data` while returning back through the recursion.
- **Note:** Base case -> if `head == NULL`, return.

---

## (c) Overview of `main()` method organization

The `main()` function controls program execution:

1. **Declares head pointer**
   ```c
   struct Node *head = NULL;
2. **Creating a Linked list**
    ```c
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
3. **Reverse traversal and display**
    ```c
    printf("Reverse: \n");
    reverseTraversal(head);
---
## (d) Sample output of run
![alt text](image-2.png)
