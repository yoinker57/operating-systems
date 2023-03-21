#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
       printf("Niepoprawna ilość argumentów");
       return 1;
    }
    setbuf(stdout, NULL);
    printf("%s ", argv[0]);
    fflush(stdout);
    execl("/bin/ls", "ls", argv[1], NULL);
    return 0;
}