#include <stdbool.h>

#include "shell.h"

// typedef struct {
//     char* cmdName;
//     void (*fptr)();
// } Command;

int main(void) {
    shell_loop();
    return 0;
}
