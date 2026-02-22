// Week 5, session 1

/* Task 2.3
 * Write a C program that perform the same function as the following Python program.
 
	Python program:
	balance = 100.0

	# Display ATM menu
	print("\nATM Menu")
	print("1. Check Balance")
	print("2. Deposit Money")
	print("3. Withdraw Money")
	
	choice = int(input("Enter your choice: "))

	match choice:
		case 1:
			print(f"Current balance: {balance:.2f}")

		case 2:
			amount = float(input("Enter amount to deposit: "))
			if amount > 0:
				balance += amount
				print(f"Deposited: {amount:.2f}")
				print(f"Current balance: {balance:.2f}")
			else:
				print("Invalid deposit amount")

		case 3:
			amount = float(input("Enter amount to withdraw: "))
			if amount > 0 and amount <= balance:
				balance -= amount
				print(f"Withdrawn: {amount:.2f}")
				print(f"Current balance: {balance:.2f}")
			else:
				print("Insufficient balance or invalid amount")
		
		case _:
			print("Invalid choice. Please try again.")
 */
 
#include <stdio.h>

int main(void) {
    int choice;
    double balance = 100.0;
    double amount;

	/* Display ATM menu */
	printf("\nATM Menu\n");
	printf("1. Check Balance\n");
	printf("2. Deposit Money\n");
	printf("3. Withdraw Money\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	// complete the rest of the code
	switch (choice) {
		case 1:
			printf("Current balance: %.2f\n", balance);
			break;
		case 2:
			printf("Enter amount to deposit: ");
			scanf("%lf", &amount);
			if (amount > 0) {
				balance += amount;
				printf("Deposited: %.2f\n", amount);
				printf("Current balance: %.2f\n", balance);
			} else {
				printf("Invalid deposit amount\n");
			}
			break;
		case 3:
			printf("Enter amount to withdraw: ");
			scanf("%lf", &amount);
			if (amount > 0 && amount <= balance) {
				balance -= amount;
				printf("Withdrawn: %.2f\n", amount);
				printf("Current balance: %.2f\n", balance);
			} else {
				printf("Insufficient balance or invalid amount\n");
			}
			break;
		default:
			printf("Invalid choice. Please try again.\n");
	}

    return 0;
}