#include "libraryMethod.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char printCheck[2][50] = {"No loan possible", "On loan"};

int addData(int count, struct library* c[]){
    struct library* new = (struct library*)malloc(sizeof(struct library));
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

int deleteData(int count, struct library* c[]){
    int index;
    int i;
    readData(count, c);
    printf("\nWhich book do you want to delete(input index) : ");
    scanf("%d", &index);
    for(i=index; i<count; i++){
        c[i-1] = c[i];
    }
    c[count-1] = 0;
    printf("Deleted\n");
    return count-1;
}

void editData(int count, struct library* c[]){
    int index;
    readData(count, c);
    printf("\nWhich book do you want to edit(input index) : ");
    scanf("%d", &index);
    printBookInfo(index-1, c);
    printf("New Book Name : ");
    scanf("%s", c[index-1]->name);
    printf("New Book Number : ");
    scanf("%d", &(c[index-1]->number));
    printf("New Author : ");
    scanf("%s", c[index-1]->author);
    printf("New Publisher : ");
    scanf("%s", c[index-1]->publisher);
    printf("Edited Book No.%d\n", index);
    printBookInfo(index-1, c);
}

void printBookInfo(int num, struct library* c[]){
    printf("[%d] %s %d %s %s (%s)\n", num+1, c[num]->name, c[num]->number, c[num]->author, c[num]->publisher, printCheck[c[num]->isCheckOut]);
}

void readData(int count, struct library* c[]){
    int i;
    printf("Book Data List\n");
    for(i=0; i<count; i++){
        printf("[%d] %s %d %s %s (%s)\n", i+1, c[i]->name, c[i]->number, c[i]->author, c[i]->publisher, printCheck[c[i]->isCheckOut]);
    }
}

void saveData(int count,struct library* c[]){
    int i;
    FILE* file;
    file=fopen("data.txt", "w");
    printf("Book Data List\n");
    for(i=0; i<count; i++){
        fprintf(file, "%s %d %d %s %s\n", c[i]->name, c[i]->number, c[i]->isCheckOut, c[i]->author, c[i]->publisher);
    }
    fclose(file);
    printf("> %d books are loaded.\n", count);
}

void searchData(int count, struct library* c[]){
    int type;
    char word[50];
    int find = 0;
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
                find++;
			}
		}
		printf("%d channels are found.\n", find);
        break;
    case 2:
        for(int i=0; i<count; i++){
			if(strstr(c[i]->author, word)){
				printBookInfo(i, c);
                find++;
			}
		}
        printf("%d channels are found.\n", find);
        break;
    case 3:
        for(int i=0; i<count; i++){
			if(strstr(c[i]->publisher, word)){
				printBookInfo(i, c);
                find++;
			}
		}
        printf("%d channels are found.\n", find);
        break;
    default:
        printf("Please input corret number.\n");
        break;
    }
}