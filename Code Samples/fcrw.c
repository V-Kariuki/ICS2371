/*
This code gives an example of c usage in file handling .
It creates an input file if the file doesnt exists and prompt for user input which is temporarily stored in a buffer then 
written into this input file. The input file is then opened for reading and its contents are read and rewritten into an output file
The data from an input file could be from any range of sources including sensors and could be used as a variable for a certain function
The relative path to where your files are created is different dependent on where you need to store your file just remember to use
escape sequences for your backslashes else your code wont work
*/
#include <stdio.h>

int main() {
    FILE *inputFile, *outputFile;//recall pointers, these are pointers to the files you create
    char buffer[100];//array to hold the user input before its written to the file

    // Create input.txt and write user input to it
    printf("Enter some text: ");
    fgets(buffer, sizeof(buffer), stdin);//reads user input from your keyboard
    inputFile = fopen("C:\\Users\\kidsa\\Searches\\dsac\\ICS2371\\input.txt", "w");//Your paths will be unique
    if (inputFile == NULL) {
        printf("Error creating input.txt\n");
        return 1;
    }
    fputs(buffer, inputFile);
    fclose(inputFile);

    // Open input.txt for reading
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input.txt\n");
        return 1;
    }

    // Open output.txt for writing
    outputFile = fopen("C:\\Users\\kidsa\\Searches\\dsac\\ICS2371\\output.txt", "w");//remember the escape sequence
    if (outputFile == NULL) {
        printf("Error creating/output.txt\n");
        fclose(inputFile);
        return 1;
    }

    // Read from input file and write to output file
    while (fgets(buffer, sizeof(buffer), inputFile) != NULL) {
        fputs(buffer, outputFile);
    }

    // Close both files
    fclose(inputFile);
    fclose(outputFile);

    printf("File copied successfully.\n");
    return 0;
}
/*
Notice with every run the data in your files is overwritten?
Well I need you to modify this code and have a version that appends new data to the file rather than overwriting previous input
Happy coding:)
*/