#include <iostream>
#include "LLQueue.h"

LLQueue::LLQueue(){
    this->front = nullptr;
    this->rear = nullptr;
}
LLQueue::~LLQueue(){
    clear();
}
void LLQueue::enqueue(const int& value){

}
void LLQueue::dequeue(){

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
}
void LLQueue::showRear() const{
    if(isEmpty()){
        std::cout<<"Queue is empty"<<std::endl;
        return;
    }
    std::cout<<"element at rear: "<<rear->data<<std::endl;
}
void LLQueue::print() const{

}
void LLQueue::clear(){
    Node* temp;

}