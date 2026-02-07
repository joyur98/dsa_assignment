#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
//swap function is used because if an unsorted array is given, we cannot max heap and mean heap

//maxheap function
void maxHeap(int arr[], int n, int i){
    int largest = i; //taking as parent
    int left = 2 * i + 1; //taking as left child
    int right = 2 * i + 2; //taking as right child

    if (left < n && arr[left] > arr[largest]){ //if left child is greater then it becomes the parent
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]){ //if right child is greater then it becomes the parent
        largest = right;
    }

    if(largest != i){ //if any of the children are greater then swap with the parent
        swap(&arr[i], &arr[largest]);
        maxHeap(arr, n, largest); //it is called recursively to maintain consistency
    }

}

//minheap function, same as max heap but the smallest element is the parent
void minHeap(int arr[], int n, int i){
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] < arr[smallest]){
        smallest = left;
    }

    if(right < n && arr[right] < arr[smallest]){
        smallest = right;
    }

    if(smallest != i){
        swap(&arr[i], &arr[smallest]);
        minHeap(arr, n, smallest);
    }
}

//buildmaxheap function
void buildMaxHeap(int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--){ //to access the non leaf nodes
        maxHeap(arr, n, i);
    }
}

//buildminheap function
void buildMinHeap( int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--){
        minHeap(arr, n, i);
    }
}

//the main function
int main() {
    int arr[] = {10, 3, 5, 2, 7, 15, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before Array: ");

    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    //building max heap
    buildMaxHeap(arr, n);
    printf("Max Heap: ");

    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    //bulding min heap using same array
    int arr2[] = {10, 3, 5, 2, 7, 15, 20};
    buildMinHeap(arr2, n);
    printf("Min Heap: ");

    for (int i = 0; i < n; i++){
        printf("%d ", arr2[i]);
    }

    return 0;
}