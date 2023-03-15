#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wc.h"


struct librarystructure *init(int max_size){
    librarystructure* structure = calloc(1, sizeof(librarystructure));
    if (structure == NULL){
        return NULL;
    }
    structure->pointers_table = calloc(max_size, sizeof(char *));
    if (NULL == structure->pointers_table)
    {
        free(structure);
        return NULL;
    }
    structure->max_size = max_size;
    structure->current_size = -1;
    return structure;
}

void countingLinesWords(struct librarystructure* structure, char filename[]){
    char command[50];
    sprintf(command, "wc %s > tmp/wc.txt ", filename);
    system(command);
    FILE *fp = fopen("tmp/wc.txt", "r");
    if(fp == NULL){
        printf("Błąd otwarcia pliku");
        return;
    }
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);
    char *file_contents = (char*)calloc(file_size, sizeof(char));
    fread(file_contents, sizeof(char), file_size, fp);
    structure->pointers_table[structure->current_size+1] = file_contents;
    structure->current_size++;
    fclose(fp);
    remove("tmp/wc.txt");
};

char* getblock(struct librarystructure* structure, int idx){
    if(0 <= idx && idx <= structure->current_size){
        return structure->pointers_table[idx];
    }
    return NULL;
}
void deleteblock(struct librarystructure *structure, int idx){
    if(0 <= idx && idx <= structure->current_size){
        free(structure->pointers_table[idx]);
        while (idx < structure->current_size - 1){
            structure->pointers_table[idx] = structure->pointers_table[idx + 1];
            idx++;
        }
        structure->pointers_table[idx] = NULL;
        structure->current_size--;
    }
}

void freestructure(struct librarystructure *structure){
    for (int i = 0; i < structure->current_size; i++){
        free(structure->pointers_table[i]);
    }
    free(structure->pointers_table);
}

