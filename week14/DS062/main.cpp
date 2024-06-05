#include <iostream>
#include "LLQueue.h"

using namespace std;

int main(){
    int num;
    cin >> num;

    LLQueue que;

    for(int i=0; i<num; i++){
        if(i==0 || i==1){
            que.enqueue(1);
        }else{
            que.enqueue(que.RearP()+que.Rear());
        }
        
    }

    int fibo = que.Rear();

    for(int i=0; i<num; i++){
        if(i==0){
            cout<<"1st : ";
        }else if(i==1){
            cout<<"2nd : ";
        }else if(i==2){
            cout<<"3rd : ";
        }else{
            cout<<i+1<<"th : ";
        }
        cout<<que.Front()<<endl;
        que.dequeue();
    }
    cout<<"=> fibonacci("<<num<<") : "<<fibo<<endl;

    return 0;
}