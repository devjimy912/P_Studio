#include "MyCircularQueue.h"

void MyCircularQueue::initialize(){
    front = 0;
    rear = 0;
}
bool MyCircularQueue::isEmpty() const{
    return front == rear;
}
bool MyCircularQueue::isFull() const{
    return size() == maxsize-1;
}
void MyCircularQueue::enqueue(const element& e){
    if(isFull()){
	    std::cout << "Queue is full" << std::endl;
    }else {
        rear = (rear + 1) % maxsize;
        // cout<<"data : "<< e.num;
        list[rear] = e;
        // cout<<" : "<< list[rear].num <<endl;
    }
}
void MyCircularQueue::dequeue(){
    if(front == rear){
        std::cout<<"=> Queue is empty!"<<std::endl;
    }else {
        front = (front + 1) % maxsize;
    }
}
element MyCircularQueue::Front(){
    return list[front+1];
}
element MyCircularQueue::Rear(){
    return list[rear];
}
MyCircularQueue::MyCircularQueue(int size){
    maxsize = size;
    front = 0;
    rear = 0;
    list = new element[maxsize];
}
MyCircularQueue::~MyCircularQueue(){
    delete[] list;
}

void MyCircularQueue::print() const {
    int temp;
    for(int i=front; i<front+size(); i++){
        if(i==front){
            temp = (i%maxsize)+1 == maxsize ? 0 : (i%maxsize)+1;
            std::cout<<list[temp].num;
        }else{
            temp = (i%maxsize)+1 == maxsize ? 0 : (i%maxsize)+1;
            std::cout<<" => "<<list[temp].num;
        }
    }
    std::cout<<std::endl;
}

int MyCircularQueue::size() const{
    return (rear-front + maxsize)%maxsize;
}

void MyCircularQueue::printDetail() const{
    std::cout<<"Size : "<< size() <<std::endl;
    print();
    std::cout<<"Index :";
    int temp;
    for(int i=front; i<front+size(); i++){
        temp = (i%maxsize)+1 == maxsize ? 0 : (i%maxsize)+1;
        std::cout<< " " << temp <<" ";
    }
    std::cout<<std::endl;
    std::cout<<"Front : "<< front%maxsize <<", rear : "<< rear%maxsize <<std::endl;
}