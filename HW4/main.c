#include "libraryMethod.h"
#include <stdio.h>
#include <stdlib.h>

int loadData(struct library* c[]);

int main(){
    int no; // amount of book
    struct library* bookList[SIZE]; // book list
    int menu; // menu number 
    int onoff = 1;

    no = loadData(bookList);

    while(onoff){
        printf(">> What do you want? (1. read, 2. add, 3. edit, 4. delete, 5. search, 6. save, 7. loanSystem, 8. exit)\n>> Input : ");
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
            break;
        case 4:
            no = deleteData(no, bookList);
            break;
        case 5:
            searchData(no, bookList);
            break;
        case 6:
            saveData(no, bookList);
            break;
        case 7:
            loanSystem(no, bookList);
            break;
        case 8:
            printf("Exit program.\n");
            onoff = 0;
            break;
        default:
            printf("Please input corret number.\n");
            break;
        }
    }

    return 0;
}

int loadData(struct library* c[]){
    int no = 0;
    FILE* file;

    file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("File open failed.\n");
        return 0; // 파일 열기 실패 처리
    }

    while(1){
        struct library* t = (struct library*)malloc(sizeof(struct library));
        if (t == NULL) {
            printf("Memory allocation failed.\n");
            break; // 메모리 할당 실패 처리
        }
        int r = fscanf(file, "%s %d %d %s %s", t->name, &(t->number), &(t->isCheckOut), t->author, t->publisher);
        if(r < 5) { // 항목 수 확인 수정
            free(t); // 읽기 실패한 경우 할당된 메모리 해제
            break; // 파일의 끝에 도달했거나 읽기 오류 발생
        }
        c[no] = t;
        no++;
    }
    fclose(file);
    printf("> %d books are loaded.\n", no);
    return no;
}