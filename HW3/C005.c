// Enter your student ID and Fullname

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 50

char LNAME[5][30]={"Graphite","Opal","Bronze","Silver","Gold"}; // labels by level

struct st_channel{
	char name[100]; // Channel name
	int count;	  // # of subscriptions
	int level;	  // index of level (0~4)
};

int loadData(struct st_channel* c[]); 
int findLevel(int num); 
void printStatistics(struct st_channel* c[], int size);
void printChannels(struct st_channel* c[], int size);
void pickupRandomChannels(struct st_channel* c[], int size);
void searchChannel(struct st_channel* c[], int size);
int addChannel(struct st_channel* c[], int size);
void updateChannel(struct st_channel* c[], int size);
int deleteChannel(struct st_channel* c[], int size);
void makeReport(struct st_channel* c[], int size); 

int main(void) {
	int no;	// amount of channels
	struct st_channel* clist[SIZE]; // channel list
	int menu; // menu number 

	srand(time(0));
	no = loadData(clist);

	while(1)
	{
		// Print menu
		printf("\n[1]List [2]Statistics [3]Random pick [4]Search [5]Add [6]Modify [7]Delete [8]Report [0]Exit\n> Enter a menu >> ");
		scanf("%d",&menu);	

		if(menu==1){
			printChannels(clist, no); // Print all list of channels
		}
		else if(menu==2){
			printStatistics(clist, no);	// Print statistics of each level
		}
		else if(menu==3){
			pickupRandomChannels(clist, no); // Pick up random channels
		}
		else if(menu==4){
			searchChannel(clist, no);	// Search a channel
		}
		else if(menu==5){
			no = addChannel(clist, no); // Add a channel
		}
		else if(menu==6){
			updateChannel(clist, no); // Modify a channel
		}
		else if(menu==7){
			no = deleteChannel(clist, no); // Delete a channel
		}
		else if(menu==8){
			makeReport(clist, no);	// Make a Report
		}
		else {
			break;
		}
	}
	return 0;
}

int loadData(struct st_channel* c[]){
	int no=0;
	FILE* file;

	file=fopen("channels.txt", "r");
	while(!feof(file)){
		struct st_channel* t = (struct st_channel*)malloc(sizeof(struct st_channel));
		int r=fscanf(file, "%s %d", t->name, &(t->count));
		if(r<2) break;
		t->level = findLevel(t->count);
		c[no] = t;
		no++;
	}
	fclose(file);
	printf("> %d channels are loaded.\n", no);
	return no;
}

int findLevel(int num){
	int range[5]={1000,10000,100000,1000000,10000000}; // range for level
	for(int j=0;j<5;j++)
		if(num<range[j])
			return j;
	return 0;
}

void printChannels(struct st_channel* c[], int size){
	printf("> List of Channels\n");
	for(int i=0; i<size; i++){
		printf("[%2d] %-20s %10d peoples [%s] \n",i+1, c[i]->name, c[i]->count,LNAME[c[i]->level]);
	}
}

int addChannel(struct st_channel* c[], int size){
	struct st_channel* temp;
	printf("> Add a new Channel\n");
	temp = (struct st_channel*)malloc(sizeof(struct st_channel));
	printf("> Enter a name of channel > ");
	scanf("%s", temp->name);
	printf("> Enter an amount of peoples > ");
	scanf("%d", &(temp->count));
	temp->level = findLevel(temp->count);
	c[size] = temp;
	printf("> New channel is added.\n");
	printf("[%2d] %-20s %10d peoples [%s] \n",size+1, c[size]->name, c[size]->count,LNAME[c[size]->level]);
	return size+1;
}
//finished
void printStatistics(struct st_channel* c[], int size){
	// 파라미터 : 채널정보를 저장된 구조체 포인터 배열 c, 채널정보 구조체의 개수 size
	// 리턴값 : 없음
	// 하는 일 : 모든 채널 정보에 대해 5개 등급별 채널개수와 평균 구독자수, 최대 구독자수를 가진 채널명,구독자수를 출력한다.
	//이걸 저장해서 한번에 할까. 아니면 임시로 넣고 덮어쓰고 할까..
	//덮어쓰기로 해보겠음
	int count; //전체 구독자
	int max; //최대구독자수
	int index; //최대구독자 인덱스
	int num; //채널 개수
	int i,j; //이건 반복용. 5등급. 전체반복
	printf("Statistics of Channels\n");
	for(i=0; i<5; i++){
		//각 등급당 첫번째가 필요함..그냥 0으로 하고 비교하면 되나?
		printf("%s : ", LNAME[i]);
		count = 0;
		max = 0;
		index = 0;
		num = 0;
		for(j=0; j<size; j++){
			if(i == c[j]->level){
				count += c[j]->count;
				num += 1;
				if(c[j]->count > max){
					max = c[j]->count;
					index = j;
				}
			}
		}
		//지금 버전은 여기서 바로 출력.
		float average = count/num*1.0;
		printf("%d channels, Average %.1f peoples, Top channel : %s (%d peoples)\n",num, average, c[index]->name, max);
	}
}
//finished
void pickupRandomChannels(struct st_channel* c[], int size){
	printf("> Pick up Channels\n");
	printf("> How much channels you want to pick up? > ");
//원하는 개수만큼 임의 채널을 추첨한 결과를 출력한다.
	int number, index;
	int dupl[SIZE];
	int dummy;
	int j;
	scanf("%d", &number);
	printf("Random Channels\n");
	for(int i=0; i<number; i++){
		dummy = 1;
		while(dummy){
			index = rand()%size;
			for(j=0; j<i; j++){ //중복 확인
				if(index == dupl[j]) break;
			}
			if(!i || j==i){ //첫번째 || 중복 아님
				break;
			}
		}
		dupl[i] = index; //선정된 인덱스 저장
		printf("[%d] %s (%s level, %d peoples)\n",index, c[index]->name, LNAME[c[index]->level], c[index]->count);
	}

}
//finished
void searchChannel(struct st_channel* c[], int size){
	printf("> Search Channels\n");
	printf("> Choose one (1:by peoples 2:by names) > ");
	int menu;
	int count = 0;
	scanf("%d", &menu);
//채널의 구독자수, 채널이름으로 검색한 결과를 출력한다.
	//이름 검색은 이전 과제에서 가져오고
	//수 검색은 전체에서 비교하며..
	if(menu == 1){
		int max, min;
		printf("> Enter the range of peoples (from ~ to) > ");
		scanf("%d %d", &min, &max);
		printf("Result\n");
		for(int i=0; i<size; i++){
			if(c[i]->count >= min && c[i]->count <= max){
				printf("[%d] %s  %d peoples [%s]\n", i+1, c[i]->name, c[i]->count, LNAME[c[i]->level]);
				count++;
			}
		}
		printf("%d channels are found.\n", count);
	}else if(menu == 2){
		char name[30];
		printf("> Enter a names > ");
		scanf("%s", name);
		printf("Result\n");
		for(int i=0; i<size; i++){
			if(strstr(c[i]->name, name)){
				printf("[%d] %s  %d peoples [%s]\n", i+1, c[i]->name, c[i]->count, LNAME[c[i]->level]);
				count++;
			}
		}
		printf("%d channels are found.\n", count);
	}

}
//finished
void updateChannel(struct st_channel* c[], int size){
	printf("> Modify a new Channel\n");
	printf("> Enter a number of channel > ");
//특정 번호의 채널 정보를 수정한다.
	//번호 받고 채녈 정보 출력하고 이름이랑 구독자 수 입력. 완료 메세지 출력.
	int num; //channel number
	scanf("%d", &num);
	if(num >= size || num <=0){
		printf("Wrong number.\n");
	}else{
		printf("> Channel Info.\n");
		printf("[%d] %s %d peoples [%s]\n", num, c[num-1]->name, c[num-1]->count, LNAME[c[num-1]->level]);
		printf("> Enter a new name of channel > ");
		scanf("%s", c[num-1]->name);
		printf("> Enter a new amount of peoples > ");
		scanf("%d", &(c[num-1]->count));
		c[num-1]->level = findLevel(c[num-1]->count);
		printf("> Channel info. is modified.\n");
	}
}
//finished
int deleteChannel(struct st_channel* c[], int size){
	int num, yesno;
	printf("> Delete a new Channel\n");
	printf("> Enter a number of channel > ");
//특정 번호의 채널 정보를 삭제한다.
//wrong number error - return size
//if correct -> show channel info
//change name, amount
	scanf("%d", &num);
	if(num > size || num < 1){ //Error Message
		printf("> Wrong number.\n");
		return size;
	}
	printf("> Channel Info.\n");
	printf("[%d] %s %d peoples [%s]\n", num, c[num-1]->name, c[num-1]->count, LNAME[c[num-1]->level]);
	printf("> Do you want to delete the channel? (1:Yes 0:No) > ");
	scanf("%d", &yesno);
	if(yesno){
		//how to delete...
		//해당 인덱스에 마지막 인덱스의 포인터를 옮긴다.
		c[num-1] = c[size-1];
		c[size-1] = NULL;
		printf("> Channel is deleted.\n");
		return size-1;
	}
	printf("> Cancled.\n");
	return size;
}

void makeReport(struct st_channel* c[], int size){
//[1],[2]번 메뉴의 출력을 report.txt에, 모든 채널 목록을 channels.txt에 다시 저장한다.
	FILE* report;
	FILE* channels;
	report = fopen("report.txt", "w");
	channels = fopen("channels.txt", "w");

	for(int i=0; i<size; i++){
		fprintf(channels, "%s %d\n", c[i]->name, c[i]->count);
	}
	printf("> All information of channels are saved into channels.txt.\n");
	fclose(channels);

	fprintf(report, "Channel list\n");
	for(int i=0; i<size; i++){
		fprintf(report, "[%d] %s  %d peoples [%s]\n", i+1, c[i]->name, c[i]->count, LNAME[c[i]->level]);
	}
	fprintf(report, "\nStatics of Channels\n");
	//통계 출력함수 먼저 완성하고 가져와야 할  듯..
//fprintf로 고쳐야함
	int count; //전체 구독자
	int max; //최대구독자수
	int index; //최대구독자 인덱스
	int num; //채널 개수
	int i,j; //이건 반복용. 5등급. 전체반복
	fprintf(report, "Statistics of Channels\n");
	for(i=0; i<5; i++){
		//각 등급당 첫번째가 필요함..그냥 0으로 하고 비교하면 되나?
		fprintf(report, "%s : ", LNAME[i]);
		count = 0;
		max = 0;
		index = 0;
		num = 0;
		for(j=0; j<size; j++){
			if(i == c[j]->level){
				count += c[j]->count;
				num += 1;
				if(c[j]->count > max){
					max = c[j]->count;
					index = j;
				}
			}
		}
		//지금 버전은 여기서 바로 출력.
		float average = count/num*1.0;
		fprintf(report, "%d channels, Average %.1f peoples, Top channel : %s (%d peoples)\n",num, average, c[index]->name, max);
	}
	printf("> Channel Statistics are saved into report.txt.\n");
	fclose(report);
}