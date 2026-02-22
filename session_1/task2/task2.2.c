// Week 5, session 1

/*
 * Task 2.2
 * Write a C program that converts currency using a switch statement.
 *
 * Input:
 * - amount: a floating-point number representing the amount of money.
 * - choice: an integer representing the conversion option selected by the user:
 *   1 → USD to EUR
 *   2 → EUR to USD
 *   3 → USD to GBP
 *   4 → GBP to USD
 *
 * Usage:
 * - The program displays a menu and reads the user's choice and amount
 *   from standard input.
 *
 * Example:
 * Input:
 * 2
 * 100
 *
 * Output:
 * Converted amount: 108.00 USD
 *
 * Output:
 * - Print the converted amount based on the selected option.
 * - Print an error message for an invalid menu option.
 */
 
#include <stdio.h>

int main(void) {
    int choice;
    double amount, converted;

    /* conversion rates */
    double USD_TO_EUR = 0.92;
    double EUR_TO_USD = 1.08;
    double USD_TO_GBP = 0.79;
    double GBP_TO_USD = 1.27;

    /* Display menu */
    printf("Currency Converter\n");
    printf("1. USD to EUR\n");
    printf("2. EUR to USD\n");
    printf("3. USD to GBP\n");
    printf("4. GBP to USD\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter amount: ");
    scanf("%lf", &amount);

	// Complete your code here
    switch (choice) {
        case 1:
            converted = amount * USD_TO_EUR;
            printf("Converted amount: %.2f EUR\n", converted);
            break;
        case 2:
            converted = amount * EUR_TO_USD;
            printf("Converted amount: %.2f USD\n", converted);
            break;
        case 3:
            converted = amount * USD_TO_GBP;
            printf("Converted amount: %.2f GBP\n", converted);
            break;
        case 4:
            converted = amount * GBP_TO_USD;
            printf("Converted amount: %.2f USD\n", converted);
            break;
        default:
            printf("Invalid option\n");
    }

    return 0;
}