#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
void handler(int signum){
    printf("Odebrano sygnal SIGUSR1 w %d\n",getpid());
}
void create_child(){
    if(0 == fork()){
        raise(SIGUSR1);
        printf("sygnał jest osiągalny w procesie potomnym\n");
    }
}
int main(int argc, char** argv){
    if (strcmp(argv[1],"ignore") == 0){
        struct sigaction act;
        act.sa_handler = SIG_IGN;
        sigaction(SIGUSR1, &act, NULL);
        raise(SIGUSR1);
        create_child();
    }
    else if (strcmp(argv[1],"handler") == 0){
        struct sigaction act;
        act.sa_handler = handler;
        sigaction(SIGUSR1, &act, NULL);
        raise(SIGUSR1);
        create_child();
    }
    else if(strcmp(argv[1],"mask") == 0){
        sigset_t mask;
        sigemptyset(&mask);
        sigaddset(&mask, SIGUSR1);
        sigprocmask(SIG_BLOCK, &mask, NULL);
        raise(SIGUSR1);
        create_child();
        sigset_t waiting_mask;
        sigemptyset(&waiting_mask);
        sigpending(&waiting_mask);
        printf("Signal blocked: %d PID: %d\n",sigismember(&waiting_mask,SIGUSR1),getpid());
    }
    else if(strcmp(argv[1],"pending")== 0){
        sigset_t mask;
        sigemptyset(&mask);
        sigaddset(&mask, SIGUSR1);
        sigprocmask(SIG_BLOCK, &mask, NULL);
        raise(SIGUSR1);
        if(0==fork()){
            sigset_t waiting_mask;
            sigemptyset(&waiting_mask);
            sigpending(&waiting_mask);
            printf("Child, Signal blocked: %d PID: %d\n",sigismember(&waiting_mask,SIGUSR1),getpid());
        }
        else{
            sigset_t waiting_mask;
            sigemptyset(&waiting_mask);
            sigpending(&waiting_mask);
            printf("Parent, Signal blocked: %d PID: %d\n",sigismember(&waiting_mask,SIGUSR1),getpid());
        }
    }
    else if(strcmp(argv[1],"execI")==0){

        struct sigaction act;
        act.sa_handler = SIG_IGN;
        sigaction(SIGUSR1, &act, NULL);
        raise(SIGUSR1);
        if (0 == fork()){
            execl("./exec_i","./exec_i",NULL);
        }
    }
    else if(strcmp(argv[1],"execM")==0){
        sigset_t mask;
        sigemptyset(&mask);
        sigaddset(&mask, SIGUSR1);
        sigprocmask(SIG_BLOCK, &mask, NULL);
        raise(SIGUSR1);
        execl("./exec_m","./exec_m",NULL);
    }
    else if(strcmp(argv[1],"execP")==0){
        sigset_t mask;
        sigemptyset(&mask);
        sigaddset(&mask, SIGUSR1);
        sigprocmask(SIG_BLOCK, &mask, NULL);
        raise(SIGUSR1);
        execl("./exec_p","./exec_p",NULL);
        
    }
    else{
        printf("Niepoprawny argument\n");
    }
}