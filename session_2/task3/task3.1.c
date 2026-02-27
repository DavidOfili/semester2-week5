// Week 5, Session 2

/* Task 3.1
 * Number Guessing Game
 * A program where the computer selects a random number and the person tries to guess it
 */

#include <stdio.h>
#include <stdlib.h>  // For rand(), srand(), atoi()
#include <time.h>    // For time()
#include <string.h>  // For strcspn()

int main(void) {
    char input[20];      // Buffer for input
    int guess;           // The person's guess
    int target;          // The random number to guess
    int num_guesses;     // Counter for number of guesses
    int min = 1;         // Minimum value for random number
    int max = 100;       // Maximum value for random number
    int playing = 1;     // Flag to control the main game loop
    
    /* Seed the random number generator with the current time so we get
       different random numbers each time the program runs */
    srand(time(NULL));
    
    printf("=== Number Guessing Game ===\n");
    printf("I'm thinking of a number between %d and %d\n", min, max);
    
    /* Main game loop: continues until the person chooses not to play again */
    while (playing) {
        /* Generate a random number between min and max (inclusive).
           The formula is: min + rand() % (max - min + 1)
           This ensures we get a number within the correct range */
        target = min + rand() % (max - min + 1);
        
        /* Reset the guess counter for a new game */
        num_guesses = 0;
        guess = -1;  /* Initialize to an impossible value */
        
        /* Guessing loop: continues until the person guesses correctly */
        while (guess != target) {
            printf("\nEnter your guess: ");
            
            /* Read the input as a string using fgets().
               This is safer than scanf() because it prevents buffer overflow */
            if (fgets(input, sizeof(input), stdin) == NULL) {
                printf("Error reading input. Please try again.\n");
                continue;  /* Skip to the next iteration */
            }
            
            /* Convert the string to an integer using atoi().
               atoi() returns 0 if the string is not a valid number */
            guess = atoi(input);
            
            /* Validate that the guess is within the valid range */
            if (guess < min || guess > max) {
                printf("Please enter a number between %d and %d.\n", min, max);
                continue;  /* Skip counting this as a real guess */
            }
            
            /* Increment the guess counter */
            num_guesses++;
            
            /* Compare the guess to the target and provide feedback */
            if (guess < target) {
                printf("Too low! Try a higher number.\n");
            } else if (guess > target) {
                printf("Too high! Try a lower number.\n");
            } else {
                /* The guess is correct */
                printf("Correct! You guessed the number in %d attempt(s).\n", num_guesses);
            }
            
            /* Offer a hint after 5 failed attempts */
            if (num_guesses == 5 && guess != target) {
                int mid = (min + max) / 2;
                printf("Hint: The number is ");
                if (target < mid) {
                    printf("in the lower half of the range.\n");
                } else {
                    printf("in the upper half of the range.\n");
                }
            }
        }
        
        /* Ask if the person wants to play again */
        printf("\nWould you like to play again? (yes/no): ");
        char response[10];  /* Buffer for yes/no answer */
        
        /* Read the response */
        if (fgets(response, sizeof(response), stdin) == NULL) {
            break;
        }
        
        /* Check the first character of the response.
           'y' or 'Y' means play again, anything else means quit */
        if (response[0] != 'y' && response[0] != 'Y') {
            playing = 0;  /* Exit the main loop */
        }
    }
    
    printf("\nThanks for playing!\n");
    return 0;
}
