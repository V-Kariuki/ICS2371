#include <stdio.h>

int main() {
    int arr[10] = {1, 2, 3, 4, 6, 7, 8, 9, 0}; // Given array
    int size = 9; // Current size of the array
    
    int num_to_insert = 5;
    int index_to_insert = 0;

    // Find the index to insert 5 while maintaining ascending order
    while (index_to_insert < size && arr[index_to_insert] < num_to_insert) {
        index_to_insert++;
    }

    // Shift elements to make space for 5
    for (int i = size; i > index_to_insert; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert 5 at the appropriate position
    arr[index_to_insert] = num_to_insert;
    size++; // Increase the size of the array

    // Print the array after inserting 5
    printf("Array after inserting 5:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
