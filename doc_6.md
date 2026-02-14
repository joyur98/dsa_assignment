# Program Documentation: Max Heap and Min Heap Construction

---

## (a) Explanation of data structures

The program uses arrays to implement binary heaps that is max heap and min heap.

- `int arr[]`  
  Stores the elements of the heap.  
  - Index `0` → root of the heap.  
  - Index `i` → parent of `2*i + 1` (left child) and `2*i + 2` (right child).

- Heap properties:
  - Max Heap: Parent ≥ children  
  - Min Heap: Parent ≤ children

- Variable:  
  - `int n` → number of elements in the array.
  - `int i` → index

---

## (b) Description of functions

### `void swap(int *a, int *b)`
- **Purpose:** Swaps the values of two integers.  
- **Logic:**  
  1. Stores `*a` in a temporary variable.  
  2. Assigns `*b` to `*a`.  
  3. Assigns temporary variable to `*b`.

---

### `void maxHeap(int arr[], int n, int i)`
- **Purpose:** Ensures the subtree rooted at `i` satisfies the **max heap property**.  
- **Logic:**  
  1. Assumes `i` as largest.  
  2. Compares with left and right children.  
  3. If child is larger → swap with parent.  
  4. Recursively call `maxHeap` on swapped child index.

---

### `void minHeap(int arr[], int n, int i)`
- **Purpose:** Ensures the subtree rooted at `i` satisfies the **min heap property**.  
- **Logic:**  
  1. Assumes `i` as smallest.  
  2. Compares with left and right children.  
  3. If child is smaller → swap with parent.  
  4. Recursively call `minHeap` on swapped child index.

---

### `void buildMaxHeap(int arr[], int n)`
- **Purpose:** Converts an array into a **max heap**.  
- **Logic:**  
  - Starts from last non-leaf node `(n/2 - 1)` and calls `maxHeap()` on each node up to root.

---

### `void buildMinHeap(int arr[], int n)`
- **Purpose:** Converts an array into a **min heap**.  
- **Logic:**  
  - Starts from last non-leaf node `(n/2 - 1)` and calls `minHeap()` on each node up to root.

---

## (c) Overview of `main()` method organization

The `main()` function controls program execution:

1. **Declares and initializes arrays**
    ```c
    int arr[] = {10, 3, 5, 2, 7, 15, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
2. **Printing before array**
    ```c
    printf("Before Array: ");

    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
3. **Building Max Heap and display**
    ```c
    buildMaxHeap(arr, n);
    printf("Max Heap: ");

    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
4. **Building Min Heap using separate array and display**
    ```c
    int arr2[] = {10, 3, 5, 2, 7, 15, 20};
    buildMinHeap(arr2, n);
    printf("Min Heap: ");