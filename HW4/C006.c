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
int addData(int count);
void readData(int count);
void editData(int count);
int deleteData(int count);
void searchData(int count);
void saveData(int count, char filename[50]);

int main(){
    int no; // amount of book
    struct st_book* bookList[SIZE]; // book list
    int menu; // menu number 
    int onoff = 1;

    no = loadData(booklList);

    while(onoff){
        printf(">> What do you want? (1. read, 2. add, 3. edit, 4. delete, 5. search, 6. save, 7. exit)\n>> Input : ");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1: //readData
            readData(no);
            break;
        case 2:
            no = addData(no);
            break;
        case 3:
            editData(no);
        case 4:
            no = deleteData(no);
        case 5:
            searchData(no);
        case 6:
            saveData(no);
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

int addData(int count){

}

void readData(int count){

}

void editData(int count){

}

int deleteData(int count){

}

void searchData(int count){

}

void saveData(int count, char filename[50]){

}