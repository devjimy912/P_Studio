// Enter your student ID and Fullname
// 22300658 전지명

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct st_class{
	int code;		// class code
	char name[30]; 	// class name
	int unit;		// credites
	int grading;	// grading (1:A+~F, 2:P/F)
};

char kname[2][10] = {"A+~F", "P/F"}; // String for grading

// Functions provided
int loadData(struct st_class* c[]); // Load all class list from data file.
void printAllClasses(struct st_class* c[], int csize); // Print all class list

// Functions for modifying
int addNewClass(struct st_class* c[], int csize); // Add a class into the list
void editClass(struct st_class* c[], int csize); // Modify a class in the list
void findClasses(char* name, struct st_class* c[], int csize); // Search a class by name from the list

// Functions for making
int applyMyClasses(int my[], int msize, struct st_class* c[], int csize); // Apply a class
void printMyClasses(int my[], int msize, struct st_class* c[], int csize); // Print my classes
void saveMyClass(int my[], int msize, struct st_class* c[], int csize); // Save my classes
void saveAllClasses(struct st_class* c[], int csize); // Save all class list


int main(void) {
	int no;	// menu number 
	struct st_class* classes[50]; // Class list (max. 50 classes)

	int myclass[10]; // My classes (max. 10 classes of code)
	int mycount = 0; // Amount of my classes

	srand(time(0));
	int count = loadData(classes);
	printf("> Load %d classes.\n", count);

	while(1){
		printf("\n> Menu 1.List 2.Add 3.Modify 4.Search 5.Apply 6.My classes 7.Save 0.Quit\n");
		printf(">> Menu? > ");
		scanf("%d", &no);

		if(no == 1){ 
			printf("> 1.Class list (%d classes)\n", count);
			printAllClasses(classes, count);
		}
		else if(no == 2){ 
			printf("> 2.Add a Class\n");
			count = addNewClass(classes, count);
		}
		else if(no == 3){ 
			printf("> 3.Modify a Class\n");
			editClass(classes, count);
		}
		else if(no == 4){
			printf("> 4.Search a Class\n");
			printf(">> Enter class name > ");
			char name[30];
			scanf("%s", name);
			findClasses(name, classes, count);
		}
		else if(no == 5){
			printf("> 5.Apply a class\n");
			mycount = applyMyClasses(myclass, mycount, classes, count);
			printf("%d classes has been applied.\n", mycount);
		}
		else if(no == 6){
			printf("> 6.My classes\n");
			printMyClasses(myclass, mycount, classes, count);
		}
		else if(no == 7){
			printf("> 7.Save\n");
			saveMyClass(myclass, mycount, classes, count);
			printf("\n> All my classes ware saved to my_classes.txt.\n");
			saveAllClasses(classes, count);
			printf("\n> All of class list ware saved to classes.txt.\n");
		}
		else break;
	}
	return 0;
}

int loadData(struct st_class* c[]){
	int count=0;
	FILE* file;

	file=fopen("classes.txt", "r");
	while(!feof(file)){
		c[count] = (struct st_class*)malloc(sizeof(struct st_class));
		int r = fscanf(file, "%d %s %d %d", &(c[count]->code),c[count]->name, &(c[count]->unit), &(c[count]->grading));
		if(r < 4) break;
		count++;
	}
	fclose(file);
	return count;
}

void printAllClasses(struct st_class* c[], int csize){
	for(int i=0; i<csize; i++){
		printf("[%d] %s [credit %d - %s]\n",c[i]->code, c[i]->name, c[i]->unit, kname[c[i]->grading-1]);
	}
}

void saveAllClasses(struct st_class* c[], int csize){
	FILE* file;
	file = fopen("classes.txt", "w");
	for(int i=0; i<csize; i++){
		fprintf(file, "%d %s %d %d\n",c[i]->code, c[i]->name, c[i]->unit, c[i]->grading);
	}
	fclose(file);	
}

void findClasses(char* name, struct st_class* c[], int csize){
	int count = 0;

	printf("Searching (keyword : %s)\n", name);
	for(int i=0; i<csize; i++){
		if(strstr(c[i]->name, name)){
			printf("[%d] %s [credit %d - %s]\n",c[i]->code, c[i]->name, c[i]->unit, kname[c[i]->grading-1]);
			count++;
		}
	}
	printf("%d classes found.\n", count);
}

// You must complete these functions.
int addNewClass(struct st_class* c[], int csize){
// Caution : Don't allow the duplicate class code.
// You must complete this function.

	struct st_class* p = (struct st_class*)malloc(sizeof(struct st_class));
	int dummy = 0;
	int i;
	
	do{
		dummy = 0;
		printf(">> code number > ");
		scanf("%d", &(p->code));
		for(i=0; i<csize; i++){
			if(p->code == c[i]->code){
				dummy = 1;
				printf(">> Code duplicated! Retry.\n");
				break;
			}
		}
	}while(dummy);
	printf(">> class name > ");
	scanf("%s", p->name);
	printf(">> credits > ");
	scanf("%d", &(p->unit));
	printf(">> grading (1: A+~F, 2: P/F) > ");
	scanf("%d", &(p->grading));

	c[csize] = p;
	return csize+1;
}
//editClass 이거 수정필요
void editClass(struct st_class* c[], int csize){
	struct st_class* p;
	int code;
	int dummy = 0;
	int i;

	do{//코드 찾기
		printf(">> Enter a code of class > ");
		scanf("%d", &code);
		for(i=0; i<csize; i++){
			if(code == c[i]->code){//찾음
				dummy = 1;
				break;
			}
		}
		if(!dummy) printf("> No such class.\n");
	}while(!dummy);
	
	// You must complete this section.
//코드가 없으면 다시 받고(위에서 한것처럼)
//포인터 할당은 걍 하면 될거같은데..

	p = c[i];
	
	printf("> Current: [%d] %s [credits %d - %s]\n",p->code, p->name, p->unit, kname[p->grading-1]);
	printf("> Enter new class name > ");
	scanf("%s", p->name);
	printf("> Enter new credits > ");
	scanf("%d", &(p->unit));
	printf("> Enter new grading(1:Grade, 2: P/F) > ");
	scanf("%d", &(p->grading));

	printf("> Modified.\n");

}


// You must make all these functions.
int applyMyClasses(int my[], int msize, struct st_class* c[], int csize){
	int repeater = 1;
	int code; //entered code of class 
	int i, j; //varialbe for test
	int dummy; //Test result
	while(repeater == 1){
		printf(">> Enter a class code > ");
		scanf("%d", &code);
		//Duplicate Test
		dummy = 1;
		for(i=0; i<msize; i++){ //Duplicate Test - Seaching code in my class list
			if(code == my[i]){ //Duplicated
				printf(">> Code duplicated! Retry.\n");
				dummy = 0;
				break;
			}
		}
		if(dummy){ //New code
			for(j=0; j<csize; j++){ //Seaching code in all class list
				if(code == c[j]->code){ //found
					dummy = 0;
					//printf class imformation
					printf("[%d] %s [credit %d - %s]\n", code, c[j]->name, c[j]->unit, kname[c[j]->grading-1]);
					//edit msize + add class in my class list
					my[msize] = code;
					msize++;
					//Ask more
					printf(">> Add more?(1:Yes 2:No) > ");
					scanf("%d", &repeater);
					break;
				}
			}
		}
		if(dummy){ //Not found
			printf(">> No such code of class.\n");
		}
	}
	return msize;
}

void printMyClasses(int my[], int msize, struct st_class* c[], int csize){
//수강 강좌이름을 전체에서 비교하고 같은걸 출력 또는 인덱스 임시 저장.
//해당 강좌 정보 출력 - 이건 위에 코드 있던거 같은데 그거 가져오고
	int i,j;
	int allCredit = 0;
	for(i=0; i<msize; i++){
		printf("%d. [%d]", i+1, my[i]);
		for(j=0; j<csize; j++){
			if(my[i] == c[j]->code){
				break;
			}
		}
		printf("%s [credit %d - %s]\n", c[j]->name, c[j]->unit, kname[c[j]->grading-1]);
		allCredit += c[j]->unit;
	}
	printf("All : %d credit\n", allCredit);
}

void saveMyClass(int my[], int msize, struct st_class* c[], int csize){
	FILE* file;
	file = fopen("my_classes.txt", "w+");
	int i,j;
	int credit1, credit2;
	credit1 = credit2 = 0;

	fprintf(file,"My classes\n");
	for(i=0; i<msize; i++){
		fprintf(file,"%d.", i+1);
		for(j=0; j<csize; j++){
			if(my[i] == c[j]->code){
				fprintf(file,"[%d] %s [credit %d - %s]\n", c[j]->code, c[j]->name, c[j]->unit, kname[c[j]->grading-1]);
				//여기서 1,2 추가해야함
				if(c[j]->grading == 1){
					credit1 += c[j]->unit;
				}else if(c[j]->grading == 2){
					credit2 += c[j]->unit;
				}
				break;
			}
		}
	}
	fprintf(file,"All : %d classes, %d credits (A+~F %d credits, P/F %d credits)\n", msize, credit1+credit2, credit1, credit2);
	// printf("All my classes were saved to my_classes.txt\n");
	fclose(file);
}
