#include <stdio.h>

//bubbleSort Function 
void bubbleSort(int arr[], int n, int swapCount[]) {
    int i, j, temp, totalSwaps = 0;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapCount[arr[j]]++;
                swapCount[arr[j+1]]++;
                totalSwaps++;
            }
        }
    }
    printf("Total # of swaps (Bubble Sort): %d\n", totalSwaps);
}

// SelectionSort Function
void selectionSort(int arr[], int n, int swapCount[]) {
    int i, j, min_idx, temp, totalSwaps = 0;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

        if (min_idx != i) {
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
            swapCount[arr[i]]++;
            swapCount[arr[min_idx]]++;
            totalSwaps++;
        }
    }
    printf("Total # of swaps (Selection Sort): %d\n", totalSwaps);
}

// Function that counts the swaps
void printSwapCounts(int swapCount[], int n) {
    for (int i = 0; i < n; i++) {
        if (swapCount[i] > 0)
            printf("%d: # of times %d is swapped\n", i, swapCount[i]);
    }
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int n1 = sizeof(array1)/sizeof(array1[0]);
    int swapCount1[100] = {0}; 

    printf("Array1:\n");
    bubbleSort(array1, n1, swapCount1);
    printSwapCounts(swapCount1, 100);
    printf("\n");

    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n2 = sizeof(array2)/sizeof(array2[0]);
    int swapCount2[100] = {0}; 

    printf("Array2:\n");
    selectionSort(array2, n2, swapCount2);
    printSwapCounts(swapCount2, 100);
    printf("\n");

    return 0;
}