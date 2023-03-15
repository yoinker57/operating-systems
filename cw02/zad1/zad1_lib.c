#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/times.h>

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


    FILE* input_file = fopen(input, "r");
    FILE* output_file = fopen(output, "w");
    char ch[1];
    size_t k;
    while ((k = fread(ch, sizeof(char), 1, input_file)) > 0){
        for (int i = 0; i < k; ++i) {
            if(ch[i] == search){
                ch[i] = replace;
            }
        }
        fwrite(ch, sizeof(char), k, output_file);
    }
    fclose(input_file);
    fclose(output_file);
    clock_gettime(CLOCK_REALTIME, &end);
    double real_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Library time: %f s\n", real_time);
    return 0;
}