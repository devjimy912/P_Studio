#include <iostream>
#include <string>

using namespace std;

//need fix
//convert class..
//convert template
// class Element{
// public:
//     string name;
//     Element(string str){ name = str; }
// };

template <typename T>
class MyCircularStringQueue{
public:
    int maxsize;
    int front;
    int rear;
    T *list;

    void initialize();
    bool isEmpty() const;
    bool isFull() const;
    void enqueue(const T& e);
    void dequeue();
    T Front();
    T Rear();
    MyCircularStringQueue(int size = 10);
    ~MyCircularStringQueue();
    int size() const;
};

template <typename T>
void MyCircularStringQueue<T>::initialize(){
    front = 0;
    rear = 0;
}
template <typename T>
bool MyCircularStringQueue<T>::isEmpty() const{
    return front == rear;
}
template <typename T>
bool MyCircularStringQueue<T>::isFull() const{
    return size() == maxsize-1;
}
template <typename T>
void MyCircularStringQueue<T>::enqueue(const T& e){
    if(isFull()){
	    cout << "Queue is full" << std::endl;
    }else {
        rear = (rear + 1) % maxsize;
        // cout<<"data : "<< e.num;
        list[rear] = e;
        // cout<<" : "<< list[rear].num <<endl;
    }
}
template <typename T>
void MyCircularStringQueue<T>::dequeue(){
    if(front == rear){
        cout<<"=> Queue is empty!"<<endl;
    }else {
        front = (front + 1) % maxsize;
    }
}
template <typename T>
T MyCircularStringQueue<T>::Front(){
    return list[front+1];
}
template <typename T>
T MyCircularStringQueue<T>::Rear(){
    return list[rear];
}
template <typename T>
MyCircularStringQueue<T>::MyCircularStringQueue(int size){
    maxsize = size;
    front = 0;
    rear = 0;
    list = new T[maxsize];
}
template <typename T>
MyCircularStringQueue<T>::~MyCircularStringQueue(){
    delete[] list;
}

template <typename T>
int MyCircularStringQueue<T>::size() const{
    return (rear-front + maxsize)%maxsize;
}