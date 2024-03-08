// Elysa Usma Lab Assignment #7
#include <stdio.h>

void bubbleSort(int arr[], int n, int swap[]) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swap[arr[j]]++;
            }
        }
    }
}

void selectionSort(int arr[], int n, int swap[]) {
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            swap[arr[i]]++;
        }
    }
}

void pSwap(int arr[], int n, int swap[]) {
    int i, j;
    for (i = 0; i < n; i++) {
        printf("%d: # of times %d is swapped\n", arr[i], swap[arr[i]]);
    }
    int tSwap = 0;
    for (j = 0; j < n; j++) {
        tSwap += swap[arr[j]];
    }
    printf("Total # of swaps: %d\n\n", tSwap);
}

int main() {
    int a1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int a2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int s1 = sizeof(a1) / sizeof(a1[0]);
    int s2 = sizeof(a2) / sizeof(a2[0]);

    int swap1[100] = {0}; 
    int swap2[100] = {0}; 

    printf("array1:\n");
    bubbleSort(a1, s1, swap1);
    pSwap(a1, s1, swap1);

    printf("array2:\n");
    selectionSort(a2, s2, swap2);
    pSwap(a2, s2, swap2);

    return 0;
}
