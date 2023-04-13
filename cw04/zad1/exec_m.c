#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
int main(int argc, char ** argv){
    raise(SIGUSR1);
    sigset_t mask;
    sigemptyset(&mask);
    sigpending(&mask);
    printf("Exec process, Signal blocked: %d\n",sigismember(&mask,SIGUSR1));
}