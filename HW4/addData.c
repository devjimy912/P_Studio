#include "libraryMethod.h"

int addData(int count, struct st_book* c[]){
    struct st_book* new = (struct st_book*)malloc(sizeof(struct st_book));
    printf("Book Name : ");
    scanf("%s", new->name);
    printf("Book Number : ");
    scanf("%d", &(new->number));
    printf("Author : ");
    scanf("%s", new->author);
    printf("Publisher : ");
    scanf("%s", new->publisher);
    new->isCheckOut = 0;
    c[count] = new;
    printf("Added new book\n");
    printf("[%d] %s %d %s %s\n", count, c[count]->name, c[count]->number, c[count]->author, c[count]->publisher);
    return count+1;
}