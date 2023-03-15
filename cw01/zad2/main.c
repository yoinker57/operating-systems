#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/times.h>

#ifndef DLL
#include "wc.h"
#endif

#ifdef DLL
#include <dlfcn.h>
typedef struct librarystructure
{
    char** pointers_table;
    int current_size;
    int max_size;
} librarystructure;
#endif

int main(){
    #ifdef DLL
        void *handle = dlopen("../zad1/libwc.so", RTLD_LAZY);
        if (handle == NULL) {
            printf("Cannot find library..\n");
            return -1;
        }
        struct librarystructure* (*init)(int) = dlsym(handle, "init");
        void (*countingLinesWords)(struct librarystructure*, char*) = dlsym(handle, "countingLinesWords");
        char* (*getblock)(struct librarystructure*, int) = dlsym(handle, "getblock");
        void (*deleteblock)(struct librarystructure*, int) = dlsym(handle, "deleteblock");
        void (*freestructure)(struct librarystructure*) = dlsym(handle, "freestructure");
    #endif
    char *com, *arg;
    struct librarystructure *structure = NULL;
    struct timespec start, end;
    int flag = 0;

    double real_time, user_time, sys_time;
    while(1){
        char line[100];
        printf(">>> ");
        if (strcmp(fgets(line, sizeof(line), stdin), "\n") == 0){
            continue;
        }
        com = strtok(line, " \n");
        arg = strtok(NULL, " \n"); //null bo kontynuujemy podział tego samego łańcucha znaków
        if (strcmp(com, "exit") == 0){
            break;
        }
        else if (strcmp(com, "init") == 0){
            if(flag == 1){
                printf("Tablica zostala juz stworzona\n");
                continue;
            }
            if(arg == NULL) {
                printf("Brak wymaganego argumentu\n");
                continue;
            }
            char *size;
            int num = strtol(arg, &size, 10);
            if (size == arg){
                printf("Niepoprawny argument\n");
                continue;
            }
            clock_gettime(CLOCK_REALTIME, &start);
            structure = init(num);
            clock_gettime(CLOCK_REALTIME, &end);
            flag = 1;
        }
        else if(strcmp(com, "count") == 0){
            if (flag == 0){
                printf("Nie zdefiniowano tablicy\n");
                continue;
            }
            if( arg == NULL){
                printf("Brak wymaganego argumentu\n");
                continue;
            }
            clock_gettime(CLOCK_REALTIME, &start);
            countingLinesWords(structure, arg);
            clock_gettime(CLOCK_REALTIME, &end);
        }
        else if(strcmp(com, "show") == 0){
            if (flag == 0){
                printf("Nie zdefiniowano tablicy\n");
                continue;
            }
            if( arg == NULL){
                printf("Brak wymaganego argumentu\n");
                continue;
            }
            char *size;
            int num = strtol(arg, &size, 10);
            if (size == arg){
                printf("Niepoprawny argument\n");
                continue;
            }
            clock_gettime(CLOCK_REALTIME, &start);
            printf("%s\n", getblock(structure, num));
            clock_gettime(CLOCK_REALTIME, &end);
        }
        else if(strcmp(com, "delete") == 0){
            if (flag == 0){
                printf("Nie zdefiniowano tablicy\n");
                continue;
            }
            if( arg == NULL){
                printf("Brak wymaganego argumentu\n");
                continue;
            }
            char *size;
            int num = strtol(arg, &size, 10);
            if (size == arg){
                printf("Niepoprawny argument\n");
                continue;
            }
            clock_gettime(CLOCK_REALTIME, &start);
            deleteblock(structure, num);
            clock_gettime(CLOCK_REALTIME, &end);
        }
        else if(strcmp(com, "destroy") == 0){
            if (flag == 0){
                printf("Nie zdefiniowano tablicy\n");
                continue;
            }
            clock_gettime(CLOCK_REALTIME, &start);
            freestructure(structure);
            clock_gettime(CLOCK_REALTIME, &end);
            flag = 0;
        }
        else if(strcmp(com, "\n") != 0){
            printf("Niepoprawna komenda!\n");
            continue;
        }


        real_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
        printf("Real time: %f s\n", real_time);
        struct tms buffer;
        times(&buffer);
        user_time = (double) buffer.tms_utime / CLOCKS_PER_SEC;
        sys_time = (double) buffer.tms_stime / CLOCKS_PER_SEC;
        printf("User time: %f s\n", user_time);
        printf("System time: %f s\n", sys_time);
    }

}