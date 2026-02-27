#include <stdio.h>

int main(void) {
    // for (int i = 2; i < 13; i++) {
    //     for (int j = 1; j < 13; j++) {
    //         printf("%d x %d = %d\n", i, j, i * j);
    //     }
    //     printf("\n");
    // }

    //---------------------------------
    
    // int a = 5;              // a is already set before the loop
    // for (; a <= 10; a++) {  // no init here
    //     printf("%d ", a);
    // }

    //--------------------------------
    
    // for (int i = 10, j = 0; i > 0 && j <= 10; i--, j++) {
    //     printf("i=%d, j=%d\n", i, j);
    // }

    //--------------------------------
    
    // int a = 5;
    // while (a <= 10) {
    //     printf("%d ", a);
    //     a++;    // same as the update part of for
    // }

    //-------------------------------
    
    // int x;
    // printf("Enter number of iteration: ");
    // scanf("%d", &x);
    // while(x > 0){
    //     printf("%d ", x);
    //     x--;
    // }

    //-------------------------------

    // char c;
    // do {
    //     printf("Continue? (y/n): ");
    //     scanf(" %c", &c);
    // } while (c != 'n');

    //-------------------------------
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Option One\n");
        printf("2. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("You selected Option One\n"); break;
            case 2: printf("Exiting program\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    }   while (choice != 2);


    return 0;
}