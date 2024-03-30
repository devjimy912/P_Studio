#include "libraryMethod.h"

void saveData(int count, char filename[50],struct st_book* c[]){
    FILE* file;
    file=fopen("data.txt", "w");
    printf("Book Data List\n");
    for(i=0; i<count; i++){
        fprintf(file, "%s %d %d %s %s\n", c[i]->name, c[i]->number, c[i]->isCheckOut, c[i]->author, c[i]->publisher);
    }
    fclose(file);
    printf("> %d books are loaded.\n", no);
}