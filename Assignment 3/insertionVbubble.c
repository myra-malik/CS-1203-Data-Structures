#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(int arr[], int n) {
    int temp;
    int swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        // If no two elements were swapped in the inner loop, the array is already sorted.
        if (swapped == 0) {
            break;
        }
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertionSort(arr, n);
    printf("Array sorted using Insertion Sort: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int bubbleSortedArr[] = {12, 11, 13, 5, 6};
    bubbleSort(bubbleSortedArr, n);
    printf("Array sorted using Bubble Sort: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", bubbleSortedArr[i]);
    }
    printf("\n");

    return 0;
}

/* 

Insertion sort has a time complexity of O(n) in the best case scenario if the array is already sorted. 

Bubble sort has a time complexity of O(n^2) because of the nested loop, and is nowhere near as efficicent 
as insertion sort. 

*/