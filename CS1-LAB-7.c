//
// Created by Yimer Duggan on 3/7/2024. CS 1 Lab 7
//
#include <stdlib.h>
#include <stdio.h>
#define ARRAY_SIZE 9

//swaps two indexes
void swap(int front, int back, int* list);

//bubbleSort
int * bubbleSort(int* list, int nOfElements);

//selectionSort
int * selectionSort(int* list, int nOfElements);

//prints a list
void printList(int list[], int size);

//copies an array
void arrayCopy(int list[], int size, int* copiedLocation);

//prints the data in the format specified by assignment.
void swapDataPrinter(int list[], int size, int swapCountList[]);

int main() {
    //hard codded arrays
    int Array1[ARRAY_SIZE] = {97,16,45, 63, 13, 22, 7, 58,72};
    int Array2[ARRAY_SIZE] = {90, 80, 70, 60, 50, 40, 30, 20,10};
    //allocate memory for copies and count trackers
    int ** trackerOfSwapTrackers1000_3000 = (int**) malloc(sizeof(int*)*2);
    int *arrayClone = (int*) malloc(sizeof(int)*ARRAY_SIZE);
    //Copy. sort the copy. print the results.
    arrayCopy(Array1, ARRAY_SIZE, arrayClone);
    trackerOfSwapTrackers1000_3000[0] = bubbleSort(arrayClone, ARRAY_SIZE);
    printf("Bubble Sort Array: 1\n");
    swapDataPrinter(arrayClone,ARRAY_SIZE,trackerOfSwapTrackers1000_3000[0]);
    //Copy. sort the copy. print the results.
    arrayCopy(Array2, ARRAY_SIZE, arrayClone);
    trackerOfSwapTrackers1000_3000[1] = bubbleSort(arrayClone, ARRAY_SIZE);
    printf("Bubble Sort Array: 2\n");
    swapDataPrinter(arrayClone, ARRAY_SIZE, trackerOfSwapTrackers1000_3000[1]);
    //freeing memory before reuse
    free(trackerOfSwapTrackers1000_3000[0]);
    free(trackerOfSwapTrackers1000_3000[1]);
    //Copy. sort the copy. print the results.
    arrayCopy(Array1, ARRAY_SIZE, arrayClone);
    trackerOfSwapTrackers1000_3000[0] = selectionSort(arrayClone, ARRAY_SIZE);
    printf("Selection Sort Array: 1\n");
    swapDataPrinter(arrayClone,ARRAY_SIZE,trackerOfSwapTrackers1000_3000[0]);
    //Copy. sort the copy. print the results.
    arrayCopy(Array2, ARRAY_SIZE, arrayClone);
    trackerOfSwapTrackers1000_3000[1] = selectionSort(arrayClone, ARRAY_SIZE);
    printf("Selection Sort Array: 2\n");
    swapDataPrinter(arrayClone, ARRAY_SIZE, trackerOfSwapTrackers1000_3000[1]);
    //free memory
    free(trackerOfSwapTrackers1000_3000[0]);
    free(trackerOfSwapTrackers1000_3000[1]);
    free(arrayClone);
    free(trackerOfSwapTrackers1000_3000);
    return 0;
}

//copies an array
void arrayCopy(int list[], int size, int* copiedLocation) {
    int counter;
    for (counter = 0; counter < size; counter++) {
        copiedLocation[counter] = list[counter];
    }
}

//selectionSort
int * selectionSort(int* list, int nOfElements) {
    int current, minIndex, target;
    //prep the swap tracker
    int* swapTracker1000 = (int*) calloc(nOfElements, sizeof(int));
    for (minIndex = 0; minIndex < nOfElements; minIndex++) {
        target = minIndex;
        //find the minimum.
        for (current = minIndex; current < nOfElements; current++){
            if (list[current] < list[target]){
                target = current;
            }
        }
        //minimum is swapped with the minIndex. Doesn't swap with self.
        if (target != minIndex) {
            swap(target, minIndex, list);
            swapTracker1000[target] += 1;
            swapTracker1000[minIndex] += 1;
            swap(target, minIndex, swapTracker1000);
        }
    }
    return swapTracker1000;
}

//bubbleSort
int * bubbleSort(int* list, int nOfElements)
{
    int current, next, swapped;
    //prep the swap tracker
    int* swapTracker1000 = (int*) calloc(nOfElements, sizeof(int));
    for (current = 0; current < nOfElements - 1; current++) {
        swapped = 0;
        for (next = 0; next < nOfElements - current - 1; next++) {
            //swaps when out of order.
            if (list[next] > list[next + 1]) {
                swap(next, next + 1, list);
                swapTracker1000[next] += 1;
                swapTracker1000[next+1] += 1;
                swap(next, next+1, swapTracker1000);
                swapped = 1;
            }
        }
        //Break condition should it be sorted
        if (swapped == 0)
            break;
    }
    return swapTracker1000;
}

// Function to print an array
void printList(int list[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", list[i]);
}

//swaps two indexes
void swap(int front, int back, int* list)
{
    int temp = list[front];
    list[front] = list[back];
    list[back] = temp;
}

//prints the data in the format specified by assignment.
void swapDataPrinter(int list[], int size, int swapCountList[]) {
    int i, total = 0;
    for (i = 0; i < size; i++) {
        printf("%d: %d\n", list[i], swapCountList[i]);
        total+= swapCountList[i];
    }
    printf("%d\n\n\n", total/2);
}