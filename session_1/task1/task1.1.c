// Week 5, Session 1

/*
 * Task 1.1
 *
 * Write a C program that checks whether a user has sufficient account 
 * balance to complete a purchase. The program should compare the account 
 * balance with the purchase amount and determine if the transaction can be completed.
 * 
 * Input
 * - account balance: a floating-point number
 * - purchase amount: a floating-point number
 * 
 * Output
 * - Print "Transaction Approved. Remaining balance xx.xx" if the balance is greater 
 *   than or equal to the purchase amount
 * - Otherwise, print "Insufficient Balance"
 */

#include <stdio.h>

int main(void) {
	
    float account_balance;
	float purchase_amount;
	// float balance;
	
	printf("Enter account balance: ");
    scanf("%f", &account_balance);
	
	printf("Enter purchase amount: ");
    scanf("%f", &purchase_amount);
	
	// Complete your code here
	if (account_balance >= purchase_amount) {
		account_balance -= purchase_amount;
		printf("Transaction Approved. Remaining balance %.2f\n", account_balance);
	}
	else{
		printf("Insufficient Balance!\n");
	}

	return 0;
}

