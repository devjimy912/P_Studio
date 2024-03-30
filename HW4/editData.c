#include "libraryMethod.h"

void editData(int count, struct st_book* c[]){
    int index;
    readData(c);
    printf("\nWhich book do you want to edit(input index) : ");
    scanf("%d", &index);
    printBookInfo(index-1, c);
    printf("New Book Name : ");
    scanf("%s", c[index]->name);
    printf("New Book Number : ");
    scanf("%d", &(c[index]->number));
    printf("New Author : ");
    scanf("%s", c[index]->author);
    printf("New Publisher : ");
    scanf("%s", c[index]->publisher);
    printf("Edited Book No.%d\n", count);
    printBookInfo(index-1, c);
}
