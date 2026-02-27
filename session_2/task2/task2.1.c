// Week 5, Session 2

/* Task 2.1
 * Temperature conversion with input validation
 * Converts temperatures between Celsius and Fahrenheit with error checking
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>  // For toupper function

int main(void) {
    char input[50];
    float temperature;
    char scale;
    int valid_input = 0;
    float converted_temp;
    
    printf("=== Temperature Converter ===\n");
    
    // Keep asking until valid input is provided
    // Use a do-while loop so we ask at least once
    do {
        valid_input = 0;  // Reset flag for each iteration
    
        printf("Enter temperature with scale (e.g., 23.5C or 75F): ");
        
        // Use fgets to safely read input (prevents buffer overflow)
        fgets(input, sizeof(input), stdin);
        
        // Remove the newline character from input
        // strcspn finds the position of '\n' and replaces it with null terminator
        input[strcspn(input, "\n")] = 0;
        
        // Parse the input to extract temperature and scale
        // sscanf reads formatted input from a string
        // %f reads a float, %c reads a character
        if (sscanf(input, "%f%c", &temperature, &scale) == 2) {
            
            // Validate the scale (must be 'C', 'c', 'F', or 'f')
            // Convert scale to uppercase for easier comparison
            // toupper() converts lowercase to uppercase
            scale = toupper(scale);
            
            // Check if scale is valid
            if (scale == 'C' || scale == 'F') {
                valid_input = 1;  // Input is valid, exit the loop
            } else {
                printf("Invalid scale! Please use 'C' for Celsius or 'F' for Fahrenheit.\n");
            }
        } else {
            printf("Invalid format! Use format like: 25.5C or 77F\n");
        }
        
    } while (!valid_input);  // Repeat while input is not valid
    
    // Perform conversion based on the input scale
    // Use if-else to check which scale was entered
    if (scale == 'C') {
        // Celsius to Fahrenheit: F = C * 9/5 + 32
        converted_temp = temperature * 9 / 5 + 32;
        printf("%.1f°C is equal to %.1f°F\n", temperature, converted_temp);
    } else {
        // Fahrenheit to Celsius: C = (F - 32) * 5/9
        converted_temp = (temperature - 32) * 5 / 9;
        printf("%.1f°F is equal to %.1f°C\n", temperature, converted_temp);
    }
    
    return 0;
}
