#include "LLQueue.h"
#include <iostream>

using namespace std;

int main(){
    int command;
    bool repeat = true;
    LLQueue llq;
    while (repeat){
        cout<<"1.enqueue 2.dequeue 3.showfront 4.showrear 5.displayQueue 6.exit > ";
        cin>>command;
        switch (command)
        {
        case 1:
            int num;
            cout<<"Enter a Value: ";
            cin>>num;
            llq.enqueue(num);
            break;
        case 2:
            llq.dequeue();
            cout<<endl;
            break;
        case 3:
            llq.showFront();
            break;
        case 4:
            llq.showRear();
            break;
        case 5:
            llq.print();
            break;
        case 6:
            cout<<"bye!"<<endl;
            repeat = false;
            llq.~LLQueue();
            break;
        
        default:
            break;
        }
    }
    

    return 0;
}