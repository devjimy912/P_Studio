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

void printBookInfo(int num, struct st_book* c[]){
    printf("[%d] %s %d %s %s (%s)\n", num+1, c[num]->name, c[num]->number, c[num]->author, c[num]->publisher, printCheck[c[num]->isCheckOut]);
}

void readData(int count, struct st_book* c[]){
    int i;
    char printCheck[2][50] = {"No loan possible", "On loan"};
    printf("Book Data List\n");
    for(i=0; i<count; i++){
        printf("[%d] %s %d %s %s (%s)\n", i+1, c[i]->name, c[i]->number, c[i]->author, c[i]->publisher, printCheck[c[i]->isCheckOut]);
    }
}

void saveData(int count, char filename[50],struct st_book* c[]){
    FILE* file;
    file=fopen("data.txt", "w");
    printf("Book Data List\n");
    for(i=0; i<count; i++){
        fprintf(file, "%s %d %d %s %s\n", c[i]->name, c[i]->number, c[i]->isCheckOut, c[i]->author, c[i]->publisher);
    }
    fclose(file);
    printf("> %d books are loaded.\n", no);
}

void searchData(int count, struct st_book* c[]){
    int type;
    char word[50];
    printf("Choose search type. (1. BookName 2. Author 3. Publisher): ");
    scanf("%d", &type);
	printf("Enter word : ");
	scanf("%s", word);
	printf("Result\n");
    switch (type)
    {
    case 1:
		for(int i=0; i<count; i++){
			if(strstr(c[i]->name, word)){
				printBookInfo(i, c);
				count++;
			}
		}
		printf("%d channels are found.\n", count);
        break;
    case 2:
        for(int i=0; i<count; i++){
			if(strstr(c[i]->author, word)){
				printBookInfo(i, c);
				count++;
			}
		}
        break;
    case 3:
        for(int i=0; i<count; i++){
			if(strstr(c[i]->publisher, word)){
				printBookInfo(i, c);
				count++;
			}
		}
        break;
    default:
        printf("Please input corret number.\n");
        break;
    }
}