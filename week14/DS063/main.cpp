#include <iostream>
#include "LLQueue.h"

using namespace std;

int main(){
    //횟수
    int num;
    cin>>num;
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
    int win = 3;//1 : p1, 2 : p2, 3 : draw
    //3으로 초기화한 이유는 첫날에 if에 걸리지 않기 위함.
    int count;

    // //첫번째 - 그냥 비교
    // if(p1.Front() > p2.Front()){
    //     pw1++;
    //     win = 1;
    // }else if(p1.Front() == p2.Front()){
    //     win = 3;
    // }else{
    //     pw2++;
    //     win = 2;
    // }
    // int count = p1.Front() - p2.Front(); // p1이 이겼을 것을 가정. p2가 이겼을 경우 -해주면 됨.
    // p1.dequeue();
    // p2.dequeue();

    //num >= 2 - 연산 필요
    //연산 시 필요한 거
    //자신의 현재 숫자, 이전 자신의 숫자, 이전 진 플레이어의 숫자
    for(int i=0; i<num; i++){
        cout<<"Round"<<i+1<<" - ";
        //승패에 따른 대결 숫자 변환.
        if(win == 1){
            p1.changecard(count);
        }else if(win == 2){
            p2.changecard(-count);
        }
        //카드 비교
        if(p1.Front() > p2.Front()){
            pw1++;
            win = 1;
            cout<<"P1 win!"<<endl;
        }else if(p1.Front() == p2.Front()){
            win = 3;
            cout<<"Draw"<<endl;
        }else{
            pw2++;
            win = 2;
            cout<<"P2 win!"<<endl;
        }
        // p1이 이겼을 것을 가정. p2가 이겼을 경우 -해주면 됨.
        count = p1.Front() - p2.Front();
        p1.dequeue();
        p2.dequeue();
    }
    cout<<"Final - ";
    if(pw1 > pw2){
        cout<<"P1 win!"<<endl;
    }else if(pw1==pw2){
        cout<<"Draw"<<endl;
    }else{
        cout<<"P2 win!"<<endl;
    }

    return 0;
}