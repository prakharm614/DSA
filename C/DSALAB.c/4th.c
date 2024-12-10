#include <stdio.h>
// Function to perform set union operation
void setUnion(int arr1[], int arr2[], int m, int n) {
    int i = 0, j = 0;
    
    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            printf("%d ", arr1[i]);
            i++;
        }
        else if (arr2[j] < arr1[i]) {
            printf("%d ", arr2[j]);
            j++;}
        else {
            printf("%d ", arr1[i]);
            i++;
            j++;
        } }
    // Print remaining elements of both arrays
    while (i < m) {
        printf("%d ", arr1[i]);
        i++;
    }while (j < n) {
        printf("%d ", arr2[j]);
        j++;
    }}

// Function to perform set intersection operation
void setIntersection(int arr1[], int arr2[], int m, int n) {
    int i = 0, j = 0;
    
    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            i++;
        }
        else if (arr2[j] < arr1[i]) {
            j++;
        }
        else {
            printf("%d ", arr1[i]);
            i++;
            j++;
        }
    }
}

// Function to perform set difference operation (arr1 - arr2)
void setDifference(int arr1[], int arr2[], int m, int n) {
    int i = 0, j = 0;
    
    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            printf("%d ", arr1[i]);
            i++;
        }
        else if (arr2[j] < arr1[i]) {
            j++;
        }
        else {
            i++;
            j++;
        }
    }
    
    while (i < m) {
        printf("%d ", arr1[i]);
        i++;
    }
}

int main() {
    int arr1[] = {1, 2, 4, 5, 6};
    int arr2[] = {2, 3, 5, 7};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    printf("Union of two sets: ");
    setUnion(arr1, arr2, m, n);

    printf("\nIntersection of two sets: ");
    setIntersection(arr1, arr2, m, n);

    printf("\nDifference of set1 - set2: ");
    setDifference(arr1, arr2, m, n);

    printf("\nDifference of set2 - set1: ");
    setDifference(arr2, arr1, n, m);

    return 0;
}
