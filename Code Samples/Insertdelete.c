#include <stdio.h>

int main() {
    int arr[10] = {0, 1, 2, 3, 4, 6, 7, 8, 9}; // Original array
    int size = 9; // Current size of the array

    // Print the original array
    printf("Original array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Insert the number 5 at the right position
    int insert_index = 0;
    while (insert_index < size && arr[insert_index] < 5) {
        insert_index++;
    }
    // Shift elements to make space for 5
    for (int i = size; i > insert_index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[insert_index] = 5;
    size++; // Increase the size of the array

    // Print the array after inserting 5
    printf("Array after inserting 5:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Remove the number 5 to restore the original array
    for (int i = insert_index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--; // Decrease the size of the array

    // Print the original array after removing 5
    printf("Array after removing 5:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
