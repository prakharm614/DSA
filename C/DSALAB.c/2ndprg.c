#include <stdio.h>
void insert(int arr[], int *size, int element, int position) {
    if (*size >= position) {
        for (int i = *size; i > position; i--) {
            arr[i] = arr[i - 1];}
        arr[position] = element;
        (*size)++;
        printf("Element %d inserted at position %d\n", element, position);
    } else {
        printf("Invalid position for insertion.\n");
    }}
void delete(int arr[], int *size, int position) {
    if (*size > 0 && position >= 0 && position < *size) {
        for (int i = position; i < (*size - 1); i++) {
            arr[i] = arr[i + 1];}
        (*size)--;
        printf("Element at position %d deleted.\n", position);
    } else {
        printf("Invalid position for deletion.\n");
    }}
void traverse(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);}
    printf("\n");}

int main() {
    int size, choice, element, position;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
	printf("Enter the elements: \n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]); }
    while (1) {
        printf("\nSelect your  choice:\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Traverse array\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insert(arr, &size, element, position);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                delete(arr, &size, position);
                break;
            case 3:
                traverse(arr, size);
                break;
            default:
                {printf("Invalid choice.\n");
				  return 0;}}}
    return 0;}


