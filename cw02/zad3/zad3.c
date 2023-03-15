#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

int main(void) {
    struct dirent *plik;
    struct stat st;
    long long total_size = 0;

    DIR* dir = opendir(".");

    while ((plik = readdir(dir)) != NULL) {
        stat(plik->d_name, &st);
        if (!S_ISDIR(st.st_mode)) {
            printf("%ld %s\n", st.st_size, plik->d_name);
            total_size += st.st_size;
        }
    }
    closedir(dir);
    printf("Total size: %lld\n", total_size);
    return 0;
}