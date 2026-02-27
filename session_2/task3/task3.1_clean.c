#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(void) {
    char input[20];
    int guess;
    int target;
    int num_guesses;
    int min = 1;
    int max = 100;
    int playing = 1;
    
    srand(time(NULL));
    
    printf("=== Number Guessing Game ===\n");
    printf("I'm thinking of a number between %d and %d\n", min, max);
    
    while (playing) {
        target = min + rand() % (max - min + 1);
        
        num_guesses = 0;
        guess = -1;
        
        while (guess != target) {
            printf("\nEnter your guess: ");
            
            if (fgets(input, sizeof(input), stdin) == NULL) {
                printf("Error reading input. Please try again.\n");
                continue;
            }
            
            guess = atoi(input);
            
            if (guess < min || guess > max) {
                printf("Please enter a number between %d and %d.\n", min, max);
                continue;
            }
            
            num_guesses++;
            
            if (guess < target) {
                printf("Too low! Try a higher number.\n");
            } else if (guess > target) {
                printf("Too high! Try a lower number.\n");
            } else {
                printf("Correct! You guessed the number in %d attempt(s).\n", num_guesses);
            }
            
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
        
        printf("\nWould you like to play again? (yes/no): ");
        char response[10];
        
        if (fgets(response, sizeof(response), stdin) == NULL) {
            break;
        }
        
        if (response[0] != 'y' && response[0] != 'Y') {
            playing = 0;
        }
    }
    
    printf("\nThanks for playing!\n");
    return 0;
}
