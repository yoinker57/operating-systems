#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
       printf("Niepoprawna ilość argumentów");
       return 1;
    }
    while (wait(NULL) > 0)
    return 0;
}