//Week 5, Session 2

# include <stdio.h>

int main(void){
/* Task 1.3
 * You have to decide which type of loop (for, while, do...while) to use.
 * Write a C program to read a series of integers from the user and sum them
 * until a 0 (zero) is entered. Print the sum at the end.
 */
    int num;
    int sum = 0;
    
    // use while loop to read until 0 is entered
    while (1) {
        printf("Enter an integer (0 to stop): ");
        scanf("%d", &num);
        
        if (num == 0) {
            break;
        }
        
        sum += num;
    }
    
    printf("Sum: %d\n", sum);

    return 0;
}