#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>



void Directory(char *path, const char *prefix){
    DIR *dir;
    if((dir = opendir(path)) == NULL){
        perror("błąd otwarcia pliku");
        return;
    }
    pid_t child_pid;
    struct dirent* dir_entry;
    struct stat stats;
    char file_path[PATH_MAX];
    while((dir_entry = readdir(dir)) != NULL){
        if(strcmp(dir_entry->d_name, ".")==0 || strcmp(dir_entry->d_name, "..")==0){
            continue;
        }
        strcpy(file_path, path);
        strcat(file_path, "/");
        strcat(file_path, dir_entry->d_name);
        stat(file_path, &stats);

        if(!S_ISDIR(stats.st_mode)){
            FILE *file = fopen(file_path, "r");
            if (file == NULL){
                printf("Blad otwarcia pliku\n");
                return;
            }
            size_t preflen = strlen(prefix);
            char buffer[255];
            size_t size = fread(buffer, sizeof(char), preflen, file);
            if (size < preflen){
                continue;
            }
            if (strcmp(buffer, prefix) == 0){
                printf("file path %s pid %d\n", file_path, getpid());
            }
            fclose(file);
        }
        else{
            child_pid = fork();
            if (child_pid == 0){
                strcat(path, "/");
                strcat(path, dir_entry->d_name);
                Directory(path, prefix);
                exit(0);
            }
        }
        strcpy(file_path, "");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
       printf("Niepoprawna ilość argumentów\n");
       return 1;
    }
    char path[PATH_MAX] = "";
    strcat(path, argv[1]);
    const char *prefix = argv[2];
    Directory(path, prefix);
    while (wait(NULL) > 0)
    return 0;
}
