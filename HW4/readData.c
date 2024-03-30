#include "libraryMethod.h"

void readData(int count, struct st_book* c[]){
    int i;
    char printCheck[2][50] = {"No loan possible", "On loan"};
    printf("Book Data List\n");
    for(i=0; i<count; i++){
        printf("[%d] %s %d %s %s (%s)\n", i+1, c[i]->name, c[i]->number, c[i]->author, c[i]->publisher, printCheck[c[i]->isCheckOut]);
    }
}