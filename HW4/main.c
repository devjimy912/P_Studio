#include "libraryMethod.h"
#define SIZE 50

int loadData(struct st_book* c[]);

int main(){
    int no; // amount of book
    struct library* bookList[SIZE]; // book list
    int menu; // menu number 
    int onoff = 1;

    no = loadData(booklList);

    while(onoff){
        printf(">> What do you want? (1. read, 2. add, 3. edit, 4. delete, 5. search, 6. save, 7. exit)\n>> Input : ");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1: //readData
            readData(no, bookList);
            break;
        case 2:
            no = addData(no, bookList);
            break;
        case 3:
            editData(no, bookList);
        case 4:
            no = deleteData(no, bookList);
        case 5:
            searchData(no, bookList);
        case 6:
            saveData(no, bookList);
        case 7:
            printf("Exit program.\n");
            onoff = 0;
        default:
            printf("Please input corret number.\n");
            break;
        }
    }

    return 0;
}

int loadData(struct library* c[]){
    int no=0;
    FILE* file;

    file=fopen("data.txt", "r");
    while(!feof(file)){
        struct library* t = (struct library*)malloc(sizeof(struct library));
        int r=fscanf(file, "%s %d %d %s %s", t->name, &(t->number), &(t->isCheckOut),t->author, t->publisher);
        if(r<6) break;
        c[no] = t;
        no++;
    }
    fclose(file);
    printf("> %d books are loaded.\n", no);
    return no;
}