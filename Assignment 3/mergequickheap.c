#include <stdio.h>
#include <stdlib.h>

// Function to merge two subarrays of arr[]
void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    // Merge the temp arrays back into arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to perform merge sort on arr[]
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Merge the sorted halves
        merge(arr, left, middle, right);
    }
}

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap arr[i+1] and arr[high] (or the pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

// Function to perform quick sort on arr[]
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Heapify a subtree rooted at node i, n is the size of the heap
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If the left child is larger than the root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If the right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest element is not the root
    if (largest != i) {
        int swap = arr[i];
        arr[i] = arr[largest];
        arr[largest] = swap;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort on arr[]
void heapSort(int arr[], int n) {
    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move the current root to the end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int mergeSortedArr[n];
    for (int i = 0; i < n; i++) {
        mergeSortedArr[i] = arr[i];
    }
    mergeSort(mergeSortedArr, 0, n - 1);
    printf("Array sorted using Merge Sort: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", mergeSortedArr[i]);
    }
    printf("\n");

    int quickSortedArr[n];
    for (int i = 0; i < n; i++) {
        quickSortedArr[i] = arr[i];
    }
    quickSort(quickSortedArr, 0, n - 1);
    printf("Array sorted using Quick Sort: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", quickSortedArr[i]);
    }
    printf("\n");

    int heapSortedArr[n];
    for (int i = 0; i < n; i++) {
        heapSortedArr[i] = arr[i];
    }
    heapSort(heapSortedArr, n);
    printf("Array sorted using Heap Sort: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", heapSortedArr[i]);
    }
    printf("\n");

    return 0;
}


/*

The time complexity for merge sort is O(n log n) because is divides the array in halves, which gives us 
log n time, and it runs through n iterations of this. 

The time complexity for quick sort in the worst case scenario is O(n^2) and is usually O(n log n) 
as it partitions the array into two equal halves at every recursive call, for n iterations. 

The time complexity for heap sort is also O(n log n) because the height of the tree is log n and 
it runs through n iterations. 


*/