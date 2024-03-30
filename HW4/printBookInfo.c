#include "libraryMethod.h"

void printBookInfo(int num, struct st_book* c[]){
    printf("[%d] %s %d %s %s (%s)\n", num+1, c[num]->name, c[num]->number, c[num]->author, c[num]->publisher, printCheck[c[num]->isCheckOut]);
}