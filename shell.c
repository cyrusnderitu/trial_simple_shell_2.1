#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 64

void execute_command(char* args[], int input_fd) {
    pid_t pid = fork();
    if (pid == 0) {
        if (input_fd != STDIN_FILENO) {
            dup2(input_fd, STDIN_FILENO);
            close(input_fd);
        }
        if (execvp(args[0], args) == -1) {
            perror("Command execution failed");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("Fork error");
    } else {
        wait(NULL);
    }
}

void parse_input(char* input, char* args[]) {
    int arg_index = 0;
    char* token = strtok(input, " \t\n");
    while (token != NULL) {
        args[arg_index++] = token;
        token = strtok(NULL, " \t\n");
    }
    args[arg_index] = NULL;
}

int main() {
    char input[MAX_CMD_LENGTH];
    char* args[MAX_ARGS];
    int background = 0;

    while (1) {
        printf("shell$ ");
        fflush(stdout);

        // Read user input
        if (fgets(input, MAX_CMD_LENGTH, stdin) == NULL) {
            break;
        }

        // Check for background process (ends with &)
        background = 0;
        int input_len = strlen(input);
        if (input_len > 1 && input[input_len - 2] == '&') {
            background = 1;
            input[input_len - 2] = '\n'; // Remove the '&'
        }

        // Parse input into arguments
        parse_input(input, args);

        // Handle built-in commands
        if (args[0] != NULL) {
            if (strcmp(args[0], "exit") == 0) {
                break;
            } else if (strcmp(args[0], "cd") == 0) {
                if (args[1] != NULL) {
                    if (chdir(args[1]) == -1) {
                        perror("cd");
                    }
                }
                continue;
            }
        }

        // Execute command
        if (args[0] != NULL) {
            if (background) {
                // Fork and execute in the background
                pid_t bg_pid = fork();
                if (bg_pid == 0) {
                    execute_command(args, STDIN_FILENO);
                    exit(EXIT_SUCCESS);
                }
            } else {
                execute_command(args, STDIN_FILENO);
            }
        }
    }

    return 0;
}
