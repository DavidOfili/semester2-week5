// Week 5, Session 1

/*
 * Task 1.3
 * Write a C program that perform the same function as the following Python program.
   
   Python program:
   number = int(input("Enter a number: "))
   if (number%3==0) and (number%5==0):
       print("The number is divisible by 3 and 5")
   else:
       print("The number is not divisible by both 3 and 5")
 */
 
#include <stdio.h>

int main(void) {

	// complete your code here
    int number;
    
    printf("Enter a number: ");
    scanf("%d", &number);

    if(number % 3 == 0 && number % 5 == 0) {
        puts("The number is divisible by 3 and 5");
    } else {
        puts("The number is not divisible by both 3 and 5");
    }

	return 0;
}