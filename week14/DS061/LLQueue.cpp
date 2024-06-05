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
void LLQueue::showFront() const{
    if(isEmpty()){
        std::cout<<"Queue is empty"<<std::endl;
        return;
    }
    std::cout<<"element at front: "<<front->data<<std::endl;
    return;
}
void LLQueue::showRear() const{
    if(isEmpty()){
        std::cout<<"Queue is empty"<<std::endl;
        return;
    }
    std::cout<<"element at rear: "<<rear->data<<std::endl;
    return;
}
void LLQueue::print() const{
    std::cout<<"Queue : "<<front->data;
    for(Node* i=front->link; i!=nullptr; i=i->link){
        std::cout << "->" << i->data;
    }
    std::cout<<std::endl;
}
void LLQueue::clear(){
    while(front != nullptr){
        dequeue();
    }
    return;
}