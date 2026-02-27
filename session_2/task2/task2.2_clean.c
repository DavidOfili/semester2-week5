#include <stdio.h>
#include <string.h>

int main(void) {
    char message[100];

    while (1) {
        printf("Enter a message (type quit to exit): ");
        if (fgets(message, sizeof(message), stdin) == NULL) {
            break;
        }

        size_t len = strlen(message);
        if (len > 0 && message[len - 1] == '\n') {
            message[len - 1] = '\0';
        }

        if (strcmp(message, "quit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        printf("You said: %s\n", message);
    }

    return 0;
}
