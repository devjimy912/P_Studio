#include "libraryMethod.h"

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