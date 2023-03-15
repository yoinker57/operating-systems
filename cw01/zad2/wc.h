#ifndef WC_H_INCLUDED
#define WC_H_INCLUDED

typedef struct librarystructure
{
    char** pointers_table;
    int current_size;
    int max_size;
} librarystructure;

struct librarystructure* init(int max_size);
void countingLinesWords(struct librarystructure* structure, char filename[]);
char* getblock(struct librarystructure *structure, int idx);
void deleteblock(struct librarystructure *structure, int idx);
void freestructure(struct librarystructure *structure);

#endif