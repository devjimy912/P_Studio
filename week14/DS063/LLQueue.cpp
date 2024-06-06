#include <iostream>
#include "LLQueue.h"

LLQueue::LLQueue(){
    this->front = nullptr;
    this->rear = front;
}
LLQueue::~LLQueue(){
    clear();
}
void LLQueue::enqueue(const int& value){
    Node* node = new Node(value);

    if(front == nullptr){
        front = node;
        rear = node;
    }else{
        rear->link = node;
        rear = node;
    }
    return;
}
void LLQueue::dequeue(){
    if(isEmpty()){
        std::cout<<"Queue is empty"<<std::endl;
        return;
    }
    Node* temp = front->link;
    delete front;
    front = temp;
    if(front==nullptr){
        rear = nullptr;
    }
    return;
}
bool LLQueue::isEmpty() const{
    return ( front==nullptr && rear==nullptr );
}
void LLQueue::clear(){
    while(front != nullptr){
        dequeue();
    }
    return;
}
int LLQueue::Front() const{
    return front->data;
}
void LLQueue::changecard(int n){
    front->data = front->data + n - 1;
    return;
}