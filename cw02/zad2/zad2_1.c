#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/times.h>

int main(int argc, char *argv[]){
    if (argc != 3){
        printf("Za mało argumentów lub za dużo argumentów");
        return 1;
    }
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);

    char* input = argv[1];
    char* output = argv[2];

    FILE* input_file = fopen(input, "rb");
    FILE* output_file = fopen(output, "wb");

    char ch[1];
    fseek(input_file, -1, SEEK_END);

    while (ftell(input_file) != 0){
        fread(ch, sizeof(char), 1, input_file);
        fwrite(ch, sizeof(char), 1, output_file);
        fseek(input_file, -2, SEEK_CUR);
    }
    fread(ch, sizeof(char), 1, input_file);
    fwrite(ch, sizeof(char), 1, output_file);

    fclose(input_file);
    fclose(output_file);
    clock_gettime(CLOCK_REALTIME, &end);
    double real_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("1 char block time: %f s\n", real_time);
    return 0;
}