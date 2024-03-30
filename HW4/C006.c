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
int addData(int count, struct st_book* c[]);
void readData(int count, struct st_book* c[]);
void editData(int count, struct st_book* c[]);
int deleteData(int count, struct st_book* c[]);
void searchData(int count, struct st_book* c[]);
void saveData(int count, char filename[50], struct st_book* c[]);
void printBookInfo(int num, struct st_book* c[]);

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

void printBookInfo(int num, struct st_book* c[]){
    printf("[%d] %s %d %s %s (%s)\n", num+1, c[num].name, c[num].number, c[num].author, c[num].publisher, printCheck[c[num].isCheckOut]);
}

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
    printf("[%d] %s %d %s %s\n", count, c[count].name, c[count].number, c[count].author, c[count].publisher);
    return count+1;
}

void readData(int count, struct st_book* c[]){
    int i;
    char printCheck[2][50] = {"No loan possible", "On loan"};
    printf("Book Data List\n");
    for(i=0; i<count; i++){
        printf("[%d] %s %d %s %s (%s)\n", count+1, c[count].name, c[count].number, c[count].author, c[count].publisher, printCheck[c[count].isCheckOut]);
    }
}

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
}

void searchData(int count, struct st_book* c[]){
    int type;
    printf("Choose search type. (1. BookName 2. Author 3. Publisher): ");
    scanf("%d", &type);
}

void saveData(int count, char filename[50],struct st_book* c[]){

}