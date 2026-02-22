// Week 5, Session 1

/*
 * Task 1.4
 * Write a C program that perform the same function as the following Python program.
   
   Python program:
   order_amount = float(input("Enter order amount: "))
   is_premium = int(input("Is customer a premium member? (1 = Yes, 0 = No): "))
   is_blacklisted = int(input("Is customer blacklisted? (1 = Yes, 0 = No): "))

   if (order_amount > 100 or is_premium == 1) and not is_blacklisted:
       print("Discount Applied")
   else:
       print("No Discount")
 */
 
#include <stdio.h>

int main(void) {
	float order_amount;
	int is_premium;
	int is_blacklisted;
	
	printf("Enter order amount: ");
    scanf("%f", &order_amount);
	
	printf("Is customer a premium member? (1 = Yes, 0 = No): ");
    scanf("%d", &is_premium);
	
	printf("Is customer blacklisted? (1 = Yes, 0 = No): ");
    scanf("%d", &is_blacklisted);
	
	// Complete the rest of the code
    if ((order_amount > 100 || is_premium == 1) && (!is_blacklisted)) { 
        printf("Discount Applied\n"); 
    } else { 
        printf("No Discount\n"); 
    }

	return 0;
}