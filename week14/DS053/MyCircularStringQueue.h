#include <iostream>
#include <string>

using namespace std;

//need fix
//convert class..
class Element{
public:
    string name;
    Element(string str){ name = str; }
};

class MyCircularStringQueue{
public:
    int maxsize;
    int front;
    int rear;
    Element *list;

    void initialize();
    bool isEmpty() const;
    bool isFull() const;
    void enqueue(const Element& e);
    void dequeue();
    Element Front();
    Element Rear();
    MyCircularStringQueue(int size = 10);
    ~MyCircularStringQueue();
    int size() const;
};

void MyCircularStringQueue::initialize(){
    front = 0;
    rear = 0;
}
bool MyCircularStringQueue::isEmpty() const{
    return front == rear;
}
bool MyCircularStringQueue::isFull() const{
    return size() == maxsize-1;
}
void MyCircularStringQueue::enqueue(const Element& e){
    if(isFull()){
	    cout << "Queue is full" << std::endl;
    }else {
        rear = (rear + 1) % maxsize;
        // cout<<"data : "<< e.num;
        list[rear] = e;
        // cout<<" : "<< list[rear].num <<endl;
    }
}
void MyCircularStringQueue::dequeue(){
    if(front == rear){
        cout<<"=> Queue is empty!"<<endl;
    }else {
        front = (front + 1) % maxsize;
    }
}
Element MyCircularStringQueue::Front(){
    return list[front+1];
}
Element MyCircularStringQueue::Rear(){
    return list[rear];
}
MyCircularStringQueue::MyCircularStringQueue(int size){
    maxsize = size;
    front = 0;
    rear = 0;
    list = new Element[maxsize];
}
MyCircularStringQueue::~MyCircularStringQueue(){
    delete[] list;
}

int MyCircularStringQueue::size() const{
    return (rear-front + maxsize)%maxsize;
}