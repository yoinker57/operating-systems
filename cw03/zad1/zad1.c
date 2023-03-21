#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number_of_processes>\n", argv[0]);
        exit(1);
    }
    int n = atoi(argv[1]);

    for (int i = 0; i < n; i++) {
        pid_t pid = fork();
        if (pid == 0){
            printf("Parent PID: %d, Child PID: %d\n", getppid(), getpid());
            exit(0);
        }
    }

    while (wait(NULL)> 0);
    printf("%s\n", argv[1]);
    return 0;
}