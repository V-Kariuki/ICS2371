#include <stdio.h>
#include <stdlib.h> // Required for dynamic memory allocation functions

// Function to modify the value of an integer using a pointer
void modifyValue(int* ptr) {
    *ptr = 20; // Modifies the value stored at the memory location pointed to by ptr
}

int main() {
    // Declaring and initializing variables
    int x = 10;
    int* ptr = &x; // Initializing ptr with the address of x
    printf("Initial value of x: %d\n", *ptr);// the value x is stored
    printf("Initial memory location of x: %d\n", &ptr);

    // Accessing and modifying values using pointers
    printf("Initial value of x: %d\n", x);
    //int y=15;
    //int * ptry =  &y;
    //printf("Initial memory location of y: %d\n", &ptry);
    *ptr = 15; // Modifying the value of x indirectly through ptr
    printf("Modified value of x: %d\n", x);

    // Using pointer arithmetic with arrays
    int arr[5] = {1, 2, 3, 4, 5};
    int* arrPtr = arr; // Points to the first element of the array
    printf("Array elements: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(arrPtr + i)); // Accessing array elements using pointer arithmetic
    }
    printf("\n");

    // Dynamic memory allocation using pointers
    int* dynamicPtr = malloc(5 * sizeof(int)); // Allocating memory for an array of 5 integers
    if (dynamicPtr != NULL) {
        printf("Dynamic memory allocated successfully.\n");
        for (int i = 0; i < 5; i++) {
            dynamicPtr[i] = i + 1; // Assigning values to the dynamically allocated array
        }
        printf("Dynamic array elements: ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", dynamicPtr[i]); // Printing dynamically allocated array elements
            printf("%d ", &dynamicPtr[i]); // Printing dynamically allocated array elements
        }
        printf("\n");
        free(dynamicPtr); // Freeing dynamically allocated memory
    } else {
        printf("Failed to allocate dynamic memory.\n");
    }

    // Passing pointers to functions
    modifyValue(&x); // Passing the address of x to modifyValue function
    printf("Modified value of x after function call: %d\n", x);

    return 0;
}
