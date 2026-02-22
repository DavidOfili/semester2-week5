// Week 5, Session 1
// Task 2.1

/*
 * Write a C program that takes 3 arguments from the command-line
 * that performs basic arithmetic operations
 
 * Input
 * - num1: a floating-point number
 * - operation: a character representing each basic arithmetic operation
 *   ('+', '-', 'x', or '/'). Use 'x' for multiplication instead of '*' 
 *    to avoid shell globbing issues on the CLI
 * - num2: a floating-point number
 *
 * Output:
 * - print the result of the aritmetic operation
 * - print "Error, division by zero!" for divide operation with num2 equals to zero 
 *
 * Usage: 
 *   ./calc num1 operation num2
 * Example: 
 *   ./calc 5.0 + 3.5
 *
 */

#include <stdio.h>
#include <stdlib.h>  // Required for atof() function

int main(int argc, char *argv[]) {
    float num1, num2;
    char operation;
    float result;
    
    // Check if the correct number of arguments is provided
    if (argc != 4) {
        printf("Usage: %s number1 operation number2\n", argv[0]);
        printf("Example: %s 5.0 + 3.5\n", argv[0]);
        printf("Operations: +, -, x, /\n");  // Note 'x' instead of '*'
        return 1;
    }
    
    // Convert command-line arguments to numbers and operation
    // atof() converts a string (ASCII) to a floating-point (float) number
    num1 = atof(argv[1]);  // Convert first argument to float
    operation = argv[2][0];  // Just take the first character of the second argument
    num2 = atof(argv[3]);  // Convert third argument to float
    
    // Complete your code here
	switch(operation){
		case '+':
			result = num1 + num2;
			break;
		case '-':
			result = num1 - num2;
			break;
		case 'x':
			result = num1 * num2;
			break;
		case '/':
			if (num2 == 0) {
				printf("Error, division by zero!\n");
				return 1;
			}
			result = num1 / num2;
			break;
		default:
			printf("Operation not defined!\n");
	}
    
    printf("Result: %.2f\n", result);
    
    return 0;
}


/*
 * Advanced tasks:
 * - (1) Add error handling for non-numeric inputs
 * - (2) Add more operations, such as modulo (%), power (^)
 */