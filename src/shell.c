#include "shell.h"

void handle_user_input(char* input) {
    if (strcmp(input, "exit") == 0) {
        exit(0);
    }
}

void shell_loop() {

    char buffer[128];

    while (true) {

        printf("> ");

        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            size_t len = strlen(buffer);
            if (len > 0 && buffer[len - 1] == '\n') {
                buffer[len - 1] = '\0';
            }

            handle_user_input(buffer);

        } else {
            fprintf(stderr, "Error reading input.\n");
        }

    }


}
