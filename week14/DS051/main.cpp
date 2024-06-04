#include <iostream>
#include "MyCircularQueue.h"

using namespace std;

int main(){
    MyCircularQueue que;

    int num;

    // num = 10;

    // cout<<"===== Enqueue x "<<num<<" ====="<<endl;
    // for(int i=0; i<num; i++){
    //     que.enqueue(i+1);
    // }
    // que.printDetail();

    // num = 1;

    // cout<<"===== Dequeue x "<<num<<" ====="<<endl;
    // for(int i=0; i<num; i++){
    //     que.dequeue();
    // }
    // que.printDetail();

    // cout<<"===== Enqueue x "<<num<<" ====="<<endl;
    // for(int i=0; i<num; i++){
    //     que.enqueue(i+1);
    // }
    // que.printDetail();
    // // element temp = que.rear();
    // cout<<"Rear index data : "<<que.Rear().num<<endl;

    num = 1;

    cout<<"===== Dequeue x "<<num<<" ====="<<endl;
    for(int i=0; i<num; i++){
        que.dequeue();
    }
    que.printDetail();

    num = 7;

    cout<<"===== Enqueue x "<<num<<" ====="<<endl;
    for(int i=0; i<num; i++){
        que.enqueue(i+1);
    }
    que.printDetail();

    num = 3;

    cout<<"===== Dequeue x "<<num<<" ====="<<endl;
    for(int i=0; i<num; i++){
        que.dequeue();
    }
    que.printDetail();

    num = 6;

    cout<<"===== Enqueue x "<<num<<" ====="<<endl;
    for(int i=0; i<num; i++){
        que.enqueue(i+1);
    }
    que.printDetail();

    return 0;
}