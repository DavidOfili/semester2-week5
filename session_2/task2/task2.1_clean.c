// Week 5, Session 2

/* Task 2.1
 * Temperature conversion with input validation
 * Converts temperatures between Celsius and Fahrenheit with error checking
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char input[50];
    float temperature;
    char scale;
    int valid_input = 0;
    float converted_temp;
    
    printf("=== Temperature Converter ===\n");
    
    do {
        valid_input = 0;
    
        printf("Enter temperature with scale (e.g., 23.5C or 75F): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
        
        if (sscanf(input, "%f%c", &temperature, &scale) == 2) {
            scale = toupper(scale);
            
            if (scale == 'C' || scale == 'F') {
                valid_input = 1;
            } else {
                printf("Invalid scale! Please use 'C' for Celsius or 'F' for Fahrenheit.\n");
            }
        } else {
            printf("Invalid format! Use format like: 25.5C or 77F\n");
        }
        
    } while (!valid_input);
    
    if (scale == 'C') {
        converted_temp = temperature * 9 / 5 + 32;
        printf("%.1f°C is equal to %.1f°F\n", temperature, converted_temp);
    } else {
        converted_temp = (temperature - 32) * 5 / 9;
        printf("%.1f°F is equal to %.1f°C\n", temperature, converted_temp);
    }
    
    return 0;
}
