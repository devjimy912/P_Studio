/*
Programming Studio C003
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int findRoom(int persons[5]); // 5개의 호실 중 빈 베드가 있는 방을 찾아낸다. (리턴값 1~5)
void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc); // 배정 결과를 출력한다.

int main(){
	char mnames[10][20]; // 남학생명단(최대 10명)
	int mroom[10];		// 남학생명단별 호실 배정 목록
	char wnames[10][20]; // 여학생명단(최대 10명)
	int wroom[10];		// 여학생명단별 호실 배정 목록
	int person[2][5]={0};   // 2개 층별 5개 호실의 배정 인원 수 
	int mcount=0, wcount=0; // 인원 합계 (남, 여)
	int menu;

	srand(time(0));
	printf("===========================================\n");
	printf("생활관 호실 배정 프로그램\n");
	printf("===========================================\n");
	while(1){
		printf("메뉴 : 1.남학생 등록 2.여학생 등록 0.종료 > ");
		scanf("%d", &menu);
		if(menu==0) break;
		else if(menu==1) {
			if(mcount>=10) {
				printf("정원 초과입니다. 등록불가!\n");
				continue;
			}
			printf("학생 이름은? > ");
			scanf("%s", mnames[mcount]);
			int roomno = findRoom(person[0]);
			mroom[mcount] = 100+roomno;
			printf("%s 학생 %d호실 배정되었습니다.\n", mnames[mcount], mroom[mcount]);
			mcount++;
		}
		else if(menu==2) {
			if(wcount>=10) {
				printf("정원 초과입니다. 등록불가!\n");
				continue;
			}
			printf("학생 이름은? > ");
			scanf("%s", wnames[wcount]);
			int roomno = findRoom(person[1]);
			wroom[wcount] = 200+roomno;
			printf("%s 학생 %d호실 배정되었습니다.\n", wnames[wcount], wroom[wcount]);
			wcount++;
		}
	}

	printf("===========================================\n");
	printf("생활관 호실 배정 결과는 다음과 같습니다.\n");
	printf("===========================================\n");
	printReport(mnames, mroom, mcount, wnames, wroom, wcount);

	return 0;
}

int findRoom(int persons[5]){
// 이 곳에 생각 정리와 코드 구현
/*
5개의 호실 중 빈 베드가 있는 방을 랜덤으로 찾아낸다. 2명 모두 배정된 호실을 배정하면 안됨!
일단 랜덤한 방을 선택해
그리고 사람이 둘이면 다시해
그렇게 해서 한사람이하면 해당 방을 리턴하는거지
아 그리고 여기서 해당 방의 인원도 기록해야하네
*/
    int randomRoom;
    do{
        randomRoom = rand()%5;
    }while(persons[randomRoom]>=2);
	persons[randomRoom]++;
    return randomRoom+1;
}

void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc){
// 이 곳에 생각 정리와 코드 구현
/*
생활관 호실 배정 결과를 출력한다. (남학생 명단 및 호실, 여학생 명단 및 호실, 호실별 배정 명단)
이건 걍 예시대로 하면 될듯
*/
	int i,j;
	// char ar[10][2][20];//10개의 방, 2명의 이름. 없는건 \0으로 가능한가..?
	// for(i=0; i<10; i++){
	// 	for(j=0; j<2; j++){
	// 		strcmp(ar[i][j], "0");
	// 	}
	// }
	printf("남학생 명단 (%d명)\n", mc);
	for(i=0;i<mc; i++){
		printf("%d. %s [%d호]\n", i+1, mn[i],mr[i]);
		// if(!strcmp(ar[mr[i]-101][0], "0")){
		// 	strcpy(mn[i], ar[mr[i]-101][0]);
		// }else if(!strcmp(ar[mr[i]-101][1], "0")){
		// 	strcpy(mn[i], ar[mr[i]-101][1]);
		// }
	}
	printf("여학생 명단 (%d명)\n", wc);
	for(i=0;i<wc; i++){
		printf("%d. %s [%d호]\n", i+1, wn[i],wr[i]);
		// if(!strcmp(ar[mr[i]-201][0], "0")){
		// 	strcpy(mn[i], ar[mr[i]-201][0]);
		// }else if(!strcmp(ar[mr[i]-201][1], "0")){
		// 	strcpy(mn[i], ar[mr[i]-201][1]);
		// }
	}
	printf("호실별 배정 명단\n");
	for(i=0; i<5; i++){
		printf("%d호 :",101+i);
		for(j=0;j<mc; j++){
			if(mr[j] == i+101) printf(" %s",mn[j]);
		}
		printf("\n");
	}
	for(i=0; i<5; i++){
		printf("%d호 :",201+i);
		for(j=0;j<wc; j++){
			if(wr[j] == i+201) printf(" %s",wn[j]);
		}
		printf("\n");
	}
	//이건 음..
	//방전체를 반복횟수로 놓고
	//방번호로 찾아서 적는게 나은듯
	//아니면 이 함수내에서 명단을 출력하는 동시에 방에 사람을 넣는게 나을지도
	// for(i=0; i<10; i++){
	// 	printf("%d호 : ",101+(i/5*100));
	// 	if(strcmp(ar[i][0], "0")){
	// 		printf(" %s",ar[i][0]);
	// 	}else if(strcmp(ar[i][1], "0")){
	// 		printf(" %s",ar[i][0]);
	// 	}
	// 	printf("\n");
	// }
}
