//Week 5, Session 2

# include <stdio.h>
# include <string.h>

int main(void){
/* Task 1.2a
 * Complete the following while loop in C to ask user input for a password 
 * until 'secure123' is entered.
 */
    char password[50];
    
    // compare using strcmp(str1,str2) from week 4
    while (1) {
        printf("Enter password: ");
        scanf("%s", password);
        
        if (strcmp(password, "secure123") == 0) {
            printf("Access granted!\n");
            break;
        } else {
            printf("Wrong password, try again.\n");
        }
    }
	
    return 0;
}