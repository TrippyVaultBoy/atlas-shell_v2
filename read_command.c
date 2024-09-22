#include "main.h"

void read_command(char *command) {
    printf("shellv2: ");
    
    fgets(command, 100, stdin);
    command[strcspn(command, "\n")] = 0;
}