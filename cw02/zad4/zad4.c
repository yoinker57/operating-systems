#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <ftw.h>

long long total_size = 0;

static int print(const char *path, const struct stat *st, int typeflag)
{
    if (!S_ISDIR(st->st_mode)) {  // jeśli nie jest katalogiem
        printf("%-20s %ld\n", path, (long)st->st_size);
        total_size += st->st_size;
    }
    return 0;
}

int main(int argc, char *argv[]){
    char *path = argv[1];
    struct stat st;
    stat(path, &st);
    if(!S_ISDIR(st.st_mode)){
        return -1;
    }
    ftw(path, print, 20);
    printf("Total size: %lld\n", total_size);
    return 0;
}