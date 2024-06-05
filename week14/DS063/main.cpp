#include <iostream>
#include "LLQueue.h"

using namespace std;

int main(){
    //횟수
    int num;
    //숫자 입력받기. for문 통해서 입력받고 queue에 넣어서 저장.
    int card;
    LLQueue p1;
    LLQueue p2;
    for(int i=0; i<num; i++){
        cin>>card;
        p1.enqueue(card);
    }
    for(int i=0; i<num; i++){
        cin>>card;
        p2.enqueue(card);
    }
    
    //front꺼내서 대결. 2번째부터는 계산 들어감.
    //여기 필요한게 승패-이건 bool로 연산할 거임. - 경우가 3개다. 1,2,3으로 감.
    //승점 저장은 그냥 int로.
    int pw1=0;
    int pw2=0;
    int win;//1 : p1, 2 : p2, 3 : draw

    //첫번째 - 그냥 비교
    if(p1.Front() > p2.Front()){
        pw1++;
        win = 1;
    }else if(p1.Front() == p2.Front()){
        win = 3;
    }else{
        pw2++;
        win = 2;
    }
    p1.dequeue();
    p2.dequeue();

    //num >= 2 - 연산 필요
    //연산 시 필요한 거
    //자신의 현재 숫자, 이전 자신의 숫자, 이전 진 플레이어의 숫자
    if(num > 1){
        
    }

    return 0;
}