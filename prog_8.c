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

