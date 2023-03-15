#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/times.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    if (argc != 5){
        printf("Za mało argumentów");
        return 1;
    }
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);

    char search = *argv[1];
    char replace = *argv[2];
    char* input = argv[3];
    char* output = argv[4];

    int input_file = open(input, O_RDONLY);
    int output_file = open(output, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    char buffer[1024];
    int bytes_read;
    while ((bytes_read = read(input_file, buffer, sizeof(buffer))) > 0){
        for (int i = 0; i < bytes_read; i++){
            if(buffer[i] == search){
                buffer[i] = replace;
            }
        }
        write(output_file, buffer, bytes_read);
    }
    close(input_file);
    close(output_file);
    clock_gettime(CLOCK_REALTIME, &end);
    double real_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("System real time: %f s\n", real_time);
    return 0;
}