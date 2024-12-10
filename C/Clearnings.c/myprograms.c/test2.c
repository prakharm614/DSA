#include <stdio.h>
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }}}}
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }}
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);
  
   int choice;
   printf("\nSelect sorting algorithm:\n");
   printf("1. Bubble Sort\n");
   printf("2. Selection Sort\n");
   printf("3. Insertion Sort\n");
   printf("Enter your choice: ");
   scanf("%d", &choice);

   switch (choice) {
       case 1:
           bubbleSort(arr, n);
           printf("Array after Bubble Sort: ");
           break;
       case 2:
           selectionSort(arr, n);
           printf("Array after Selection Sort: ");
           break;
       case 3:
           insertionSort(arr, n);
           printf("Array after Insertion Sort: ");
           break;
       default:
           printf("Invalid choice\n");
           return 1;
   }
   printArray(arr, n);

   return 0;
}


