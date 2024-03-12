#include <stdio.h>

int main(){
    int size;
    int stars, blank1, blank2;
    int i,j;

    printf("size : ");
    scanf("%d", &size);
//제일 먼저 생각나는건 전부 개별적인 for문으로 실행하는 건데
//규칙 찾기하면 더 간소화 가능할 듯..
/*
하나의 for문으로 엮는거 가능해보임 - 변수가 3개이므로 -(변수)로 할수있을듯
역삼각 속빈 : 
사각 속찬 : 
역삼각 속찬 : 
받침 한줄 : 
*/
    for(i=0; i<size; i++){
        for(j=0; j<i; j++){
            printf(" ");
        }
        printf("*");
        for(j=0; j<size*2-i*2-2; j++){
            printf(" ");
        }
        printf("*\n\n");
    }
    for(i=0; i<size; i++){
        for(j=0; j<size*2; j++){
            printf("*");
        }
        printf("\n\n");
    }
    for(i=0; i<size; i++){
        for(j=0; j<i; j++){
            printf(" ");
        }
        for(j=0; j<size*2-i*2; j++){
            printf("*");
        }
        printf("\n\n");
    }
    for(i=0; i<size*2; i++){
        printf("*");
    }

    return 0;
}