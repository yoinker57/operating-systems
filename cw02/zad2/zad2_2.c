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

    char ch[1024];
    size_t k;
    fseek(input_file, 0, SEEK_END);
    if (ftell(input_file) > 1024){
        fseek(input_file, -1024, SEEK_END);
        while ((k = ftell(input_file)) > 1024)
        {
            fread(ch, sizeof(char), 1024, input_file);
            for (size_t i = 0; i < 1024/2; i++)
            {
                char tmp = ch[i];
                ch[i] = ch[1023 - i];
                ch[1023 - i] = tmp;
            }
            
            fwrite(ch, sizeof(char), 1024, output_file);
            fseek(input_file, -2048, SEEK_CUR);
        }
    }
    fseek(input_file, -1024, SEEK_CUR);
    k = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);
    fread(ch, sizeof(char), k, input_file);
    for (size_t i = 0; i < k/2; i++)
        {
            char tmp = ch[i];
            ch[i] = ch[k - 1 - i];
            ch[k - 1 - i] = tmp;
        }
    fwrite(ch, sizeof(char), k, output_file);
    fclose(input_file);
    fclose(output_file);
    clock_gettime(CLOCK_REALTIME, &end);
    double real_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("1024 block time: %f s\n", real_time);
    return 0;
}