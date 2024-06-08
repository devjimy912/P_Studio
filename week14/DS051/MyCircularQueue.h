#include <iostream>

using namespace std;

struct element{
    int num;
    element(int n = 0) : num(n){}
};

class MyCircularQueue{
public:
    int maxsize;
    int front;
    int rear;
    element *list;

    void initialize();
    bool isEmpty() const;
    bool isFull() const;
    void enqueue(const element& e);
    void dequeue();
    element Front();
    element Rear();
    MyCircularQueue(int size = 10);
    ~MyCircularQueue();
    void print() const;
    int size() const;
    void printDetail() const;
};

// void MyCircularQueue::initialize(){
//     front = 0;
//     rear = 0;
// }
// bool MyCircularQueue::isEmpty() const{
//     return front == rear;
// }
// bool MyCircularQueue::isFull() const{
//     return size() == maxsize-1;
// }
// void MyCircularQueue::enqueue(const element& e){
//     if(isFull()){
// 	    cout << "Queue is full" << std::endl;
//     }else {
//         rear = (rear + 1) % maxsize;
//         // cout<<"data : "<< e.num;
//         list[rear] = e;
//         // cout<<" : "<< list[rear].num <<endl;
//     }
// }
// void MyCircularQueue::dequeue(){
//     if(front == rear){
//         cout<<"=> Queue is empty!"<<endl;
//     }else {
//         front = (front + 1) % maxsize;
//     }
// }
// element MyCircularQueue::Front(){
//     return list[front+1];
// }
// element MyCircularQueue::Rear(){
//     return list[rear];
// }
// MyCircularQueue::MyCircularQueue(int size){
//     maxsize = size;
//     front = 0;
//     rear = 0;
//     list = new element[maxsize];
// }
// MyCircularQueue::~MyCircularQueue(){
//     delete[] list;
// }
// //need fix - finish
// //problem : if index is 0, data becomes 0
// void MyCircularQueue::print() const{
//     cout<<"Queue :";
//     int temp;
//     for(int i=front; i<front+size(); i++){
//         // cout<<"list : "<< list[(i%maxsize)+1].num;
//         temp = (i%maxsize)+1 == maxsize ? 0 : (i%maxsize)+1;
//         cout<<"["<<list[temp].num<<"]";
//     }
//     cout<<endl;
// }

// int MyCircularQueue::size() const{
//     return (rear-front + maxsize)%maxsize;
// }

// void MyCircularQueue::printDetail() const{
//     cout<<"Size : "<< size() <<endl;
//     //need fix - finish
//     print();
//     //need fix - finish
//     cout<<"Index :";
//     int temp;
//     for(int i=front; i<front+size(); i++){
//         temp = (i%maxsize)+1 == maxsize ? 0 : (i%maxsize)+1;
//         cout<< " " << temp <<" ";
//     }
//     cout<<endl;
//     cout<<"Front : "<< front%maxsize <<", rear : "<< rear%maxsize <<endl;
// }
