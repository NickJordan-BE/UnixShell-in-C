#include "shell.h"
#include "utils.h"

void history(const Node *const node) {
    if (node == NULL) return;
    history(node->next);
    printf("%s\n", node->command);
}

char* mallocString(const char *const string) {
    char* new_string = malloc(sizeof(char) * 128);
    for (int i = 0; i < 128; i++) {
        new_string[i] = string[i];
    }
    return new_string;
}

Node* handle_user_input(const char *const input, const Node *const node) {

    if (strcmp(input, "exit") == 0) { // exit cmd
        printf("Exiting shell.\n");
        exit(0);
    } else if (strcmp(input, "history") == 0) {
        history(node);
    } else {
        printf("Unknown command: %s\n", input);
    }


    return init_node(input, node);
}

void shell_loop() {

    char buffer[128];
    Node* cmd_history;

    while (true) {

        printf("> ");
        fflush(stdout);

        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            // Remove trailing newline if it exists
            const size_t len = strlen(buffer);
            if (len > 0 && buffer[len - 1] == '\n') {
                buffer[len - 1] = '\0';
            }

            cmd_history = handle_user_input(mallocString(buffer), cmd_history);
        } else {
            fprintf(stderr, "Error reading input or EOF encountered.\n");
            break;
        }
    }
}