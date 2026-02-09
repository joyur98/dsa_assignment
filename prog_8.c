#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//long long means that it is longer than int and long so it can hold a large number
long long comparisons = 0; //to hold the number of comparions
long long swapsCount = 0; //to hold the number of swaps

//function to print the array
void print(int arr[], int n){
    for (int i = 0; i < n;i ++){
        printf("%d", arr[i]);
    }
    printf("\n");
}

//function to perform bubble sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-i-1;j++){
            comparisons++;
            if(arr[j] > arr[j+1]){
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            swapsCount++;
            }
        }
    }
}

//function to perform selectionsort
void selectionSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        int minIndex = i;
        for (int j = i + 1; j < n; j++){
            comparisons++;
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = arr[i];
            swapsCount++;
        }
    }
}

//function to perform insertion sort
void insertionSort(int arr[], int n){
    for (int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;

        while(j>=0){
            comparisons++;
            if(arr[j] > key){
                arr[j + 1] = arr[j];
                swapsCount++;
                j--;
            }
            else{
                break;
            }
        }
        arr[j + 1] = key;
    }
}

//functions to perform merge sort
void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }
    
    for (int j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2){
        comparisons++;

         if (L[i] <= R[j]){
            arr[k++] = L[i++];
         }
        else{
            arr[k++] = R[j++];
        }

    while (i < n1){
        arr[k++] = L[i++];
    }
    while (j < n2){
        arr[k++] = R[j++];
    }
}
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}


int main() {
    int n, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 1000 + 1;

    printf("\nNumbers before sorting:\n");
    printArray(arr, n);

    printf("\nChoose Sorting Algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    comparisons = 0;
    swapsCount = 0;

    switch (choice) {
        case 1:
            bubbleSort(arr, n);
            break;
        case 2:
            selectionSort(arr, n);
            break;
        case 3:
            insertionSort(arr, n);
            break;
        case 4:
            mergeSort(arr, 0, n - 1);
            break;
        default:
            printf("Invalid choice!\n");
            return 0;
    }

    printf("\nNumbers after sorting:\n");
    printArray(arr, n);

    printf("\nPerformance Metrics:\n");
    printf("Total Comparisons: %lld\n", comparisons);

    if (choice != 4)
        printf("Total Swaps: %lld\n", swapsCount);
    else
        printf("Swaps: Not applicable for Merge Sort\n");

    return 0;
}