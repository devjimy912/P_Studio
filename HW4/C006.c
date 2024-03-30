#include <stdin.h>
//branch test
#define SIZE 50

struct library{
    char name[50]; //book name
    int number; //book number
    int isCheckOut; //0:in, 1:out
    char author[50]; //author
    char publisher[50]; //publisher
};

int loadData(struct st_book* c[]);

int main(){
    int no; // amount of book
    struct st_book* bookList[SIZE]; // book list
    int menu; // menu number 

    srand(time(0));
    no = loadData(booklList);

    return 0;
}

int loadData(struct st_book* c[]){
    int no=0;
    FILE* file;

    file=fopen("data.txt", "r");
    while(!feof(file)){
        struct st_book* t = (struct st_book*)malloc(sizeof(struct st_book));
        int r=fscanf(file, "%s %d %d %s %s", t->name, &(t->number), &(t->isCheckOut),t->author, t->publisher);
        if(r<6) break;
        c[no] = t;
        no++;
    }
    fclose(file);
    printf("> %d books are loaded.\n", no);
    return no;
}