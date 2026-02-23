// Week 5, session 1

/*
 * Task 3.2
 * Write a C program that calculates traffic violation fines
 * based on the type of violation and whether it is a repeat offense.
 *
 * Input:
 * - violation_type: an integer representing the violation type:
 *   1 → Speeding
 *   2 → Signal Jumping
 *   3 → Illegal Parking
 * - repeat_offense: an integer representing repeat offense status:
 *   0 → First-time offense
 *   1 → Repeat offense
 *
 * Output:
 * - Print the violation type such as "Violation: Speeding".
 * - Calculate and display the fine amount such as "Fine amount: xxx.xx".
 * - Apply a higher fine for repeat offenses. Repeat offenses incur a 100% fine increase (fine * 2).
 * - Print an error message for invalid violation types such as "Invalid violation type".
 *
 * Notes:
 * - Base fines:
 *   Speeding: 100
 *   Signal Jumping: 150
 *   Illegal Parking: 50
 * - The program must use a switch statement to process the violation type.
 *   
 * Example:
 * Input:
 * Enter violation type (1-Speeding, 2-Signal Jumping, 3-Illegal Parking): 1
 * Is this a repeat offense? (0-No, 1-Yes): 1
 *
 * Output:
 * Violation: Speeding
 * Repeat offense: Yes
 * Fine amount: 200.00
 */
 
 #include <stdio.h>

int main(void) {
    int violation_type;
    int repeat_offense;
    float fine = 0.0;

    printf("Enter violation type (1-Speeding, 2-Signal Jumping, 3-Illegal Parking): ");
    scanf("%d", &violation_type);

    printf("Is this a repeat offense? (0-No, 1-Yes): ");
    scanf("%d", &repeat_offense);

    /* subtask 1: Determine base fine using switch */
	// Complete your code here
    switch (violation_type) {
        case 1:
            printf("Violation: Speeding\n");
            fine = 100.0;
            break;
		case 2:
			printf("Violation: Signal Jumping\n");
			fine = 150.0;
			break;
		case 3:
			printf("Violation: Illegal Parking\n");
			fine = 50.0;
			break;

        default:
            printf("Invalid violation type\n");
            return 1;
    }

    /* subtask 2: Apply repeat offense penalty */
	// Complete your code here
	
	if (repeat_offense == 1) {
		printf("Repeat offense: Yes\n");
		fine = fine * 2;
	} else {
		printf("Repeat offense: No\n");
	}

    /* Output final fine */
    printf("Fine amount: %.2f\n", fine);

    return 0;
}


/*
 * TEST CASES:
 *
 * Test Case 1: Speeding - First-time offense
 * Input: 1, 0
 * Expected Output:
 * Violation: Speeding
 * Repeat offense: No
 * Fine amount: 100.00
 *
 * Test Case 2: Signal Jumping - Repeat offense
 * Input: 2, 1
 * Expected Output:
 * Violation: Signal Jumping
 * Repeat offense: Yes
 * Fine amount: 300.00
 *
 * Test Case 3: Illegal Parking - Repeat offense
 * Input: 3, 1
 * Expected Output:
 * Violation: Illegal Parking
 * Repeat offense: Yes
 * Fine amount: 100.00
 *
 * Test Case 4: Invalid violation type
 * Input: 5, 0
 * Expected Output:
 * Invalid violation type
 */