#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/times.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>
#include <limits.h>

clock_t start, end;
struct tms start_time;
struct tms end_time;

double function(double x){
    return (double)4/(x*x+(double)1);
}

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Niepoprawna liczba argumentów");
        return 1;
    }
    double dx = atof(argv[1]);
    int n = atoi(argv[2]);
    start = times(&start_time);
    int fd[n][2];
    double h = (double)1/(double)n;
    for (int i = 0; i<n; i++){
        pipe(fd[i]);
    }
    for(int i = 0; i<n; i++){
        double a = h * i;
        double b = h * (i+1);
        if (fork() == 0){
            close(fd[i][0]);
            double sum = 0;
            for (double j = a; j < b; j+=dx){
                sum += function(j);
            }
            write(fd[i][1], &sum, sizeof(double));
            exit(0);
        }
        close(fd[i][1]);
    }
    while(wait(NULL)>0);
    double res = 0;
    double tmp = 0;
    for (int i = 0; i < n; i++){
        read(fd[i][0], &tmp, sizeof(double));
        res += tmp;
    }
    res = res*dx;
    printf("res: %f", res);
    end = times(&end_time);
    printf("Result: %f", res);
    
    printf("dx: %f n: %d \n",dx, n);
    printf("Real time of function: %fs\n",((double) (end-start))/ sysconf(_SC_CLK_TCK));
    printf("User time of function: %fs\n",((double) (end_time.tms_utime-start_time.tms_utime))/ sysconf(_SC_CLK_TCK));
    printf("System time of function: %fs\n",((double) (end_time.tms_stime-start_time.tms_stime))/ sysconf(_SC_CLK_TCK));
}

