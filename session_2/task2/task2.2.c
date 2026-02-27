// Week 5, Session 2

/* Task 2.2
 * Write a C program that continuosly prompts the user to enter
 * a message and then prints it back to them. The loop should terminate
 * if the user types "quit".
 * - use fgets() + newline removal
 * - use strcmp for string comparison
 */
 
 #include <stdio.h>
 #include <string.h>
 
 int main(void) {
	/* buffer to hold user input; 100 characters should be enough for
	a simple message */
	char message[100];

	/* repeatedly prompt the user until they type "quit" */
	while (1) {
		printf("Enter a message (type quit to exit): ");

		/* fgets reads at most sizeof(message)-1 characters and
		always null-terminates the string */
		if (fgets(message, sizeof(message), stdin) == NULL) {
			/* EOF or error - break out of the loop */
			break;
		}

		/* remove the trailing newline that fgets stores, if present */
		size_t len = strlen(message);
		if (len > 0 && message[len - 1] == '\n') {
			message[len - 1] = '\0';
		}

		/* compare the input to "quit"; strcmp returns 0 when strings are equal */
		if (strcmp(message, "quit") == 0) {
			printf("Goodbye!\n");
			break;     /* exit the loop */
		}

		/* echo the message back to the user */
		printf("You said: %s\n", message);
	}

	return 0;
}
