#include <stdio.h>

// Define a union representing a variable that can be interpreted as either an integer or a float
union IntFloat {
    int intValue;
    float floatValue;
};

// Function to display the value stored in a union
void displayValue(union IntFloat value) {
    printf("Value stored in the union:\n");
    printf("Integer value: %d\n", value.intValue);
    printf("Float value: %.2f\n", value.floatValue);
}

int main() {
    // Declare and initialize a union variable
    union IntFloat number;
    number.intValue = 10;

    // Display the value stored in the union
    displayValue(number);

    // Modify the value stored in the union
    number.floatValue = 3.14;

    // Display the modified value
    displayValue(number);

    return 0;
}
