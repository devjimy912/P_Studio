#include "libraryMethod.h"

int deleteData(int count, struct st_book* c[]){
    int index;
    int i;
    readData(c);
    printf("\nWhich book do you want to delete(input index) : ");
    scanf("%d", &index);
    for(i=index; i<count; i++){
        c[i-1] = c[i];
    }
    c[count-1] = NULL;
    printf("Deleted\n");
    return count-1;
}