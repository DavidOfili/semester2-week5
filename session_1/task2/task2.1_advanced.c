// Week 5, Session 1
// Task 2.1 - Advanced

/*
 * Write a C program that takes 3 arguments from the command-line
 * that performs basic arithmetic operations with advanced features:
 * - Error handling for non-numeric inputs
 * - Additional operations: modulo (%) and power (^)
 
 * Input
 * - num1: a floating-point number
 * - operation: a character representing each basic arithmetic operation
 *   ('+', '-', 'x', '/', '%', or '^'). Use 'x' for multiplication instead of '*' 
 *    to avoid shell globbing issues on the CLI
 * - num2: a floating-point number
 *
 * Output:
 * - print the result of the aritmetic operation
 * - print "Error, division by zero!" for divide operation with num2 equals to zero 
 * - print appropriate error messages for non-numeric inputs
 *
 * Usage: 
 *   ./calc num1 operation num2
 * Example: 
 *   ./calc 5.0 + 3.5
 *
 */

#include <stdio.h>
#include <stdlib.h>  // Required for atof() function
#include <string.h>  // Required for strlen()
#include <ctype.h>   // Required for isdigit()
#include <math.h>    // Required for pow() function

// Function to validate if a string is a valid number
int is_valid_number(const char *str) {
    if (str == NULL || strlen(str) == 0) {
        return 0;
    }
    
    int has_dot = 0;
    int has_digit = 0;
    
    // Allow optional leading sign
    int start = 0;
    if (str[0] == '-' || str[0] == '+') {
        start = 1;
    }
    
    for (int i = start; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            has_digit = 1;
        } else if (str[i] == '.' && !has_dot) {
            has_dot = 1;
        } else {
            return 0;  // Invalid character found
        }
    }
    
    return has_digit;  // Valid if it has at least one digit
}

int main(int argc, char *argv[]) {
    float num1, num2;
    char operation;
    float result;
    
    // Check if the correct number of arguments is provided
    if (argc != 4) {
        printf("Usage: %s number1 operation number2\n", argv[0]);
        printf("Example: %s 5.0 + 3.5\n", argv[0]);
        printf("Operations: +, -, x, /, %%, ^\n");  // Note 'x' instead of '*'
        return 1;
    }
    
    // Validate input is numeric
    if (!is_valid_number(argv[1])) {
        printf("Error: '%s' is not a valid number\n", argv[1]);
        return 1;
    }
    
    if (!is_valid_number(argv[3])) {
        printf("Error: '%s' is not a valid number\n", argv[3]);
        return 1;
    }
    
    // Convert command-line arguments to numbers and operation
    // atof() converts a string (ASCII) to a floating-point (float) number
    num1 = atof(argv[1]);  // Convert first argument to float
    operation = argv[2][0];  // Just take the first character of the second argument
    num2 = atof(argv[3]);  // Convert third argument to float
    
    // Perform calculation based on operation
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
		case '%':
			if (num2 == 0) {
				printf("Error, division by zero!\n");
				return 1;
			}
			result = (float)((int)num1 % (int)num2);
			break;
		case '^':
			result = pow(num1, num2);
			break;
		default:
			printf("Operation not defined!\n");
	}
    
    printf("Result: %.2f\n", result);
    
    return 0;
}


/*
 * Advanced features implemented:
 * - (1) Error handling for non-numeric inputs via is_valid_number() function
 * - (2) Additional operations: modulo (%) and power (^)
 */
