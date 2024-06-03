#include <iostream>

using namespace std;

typedef struct{
    int num;
}element;

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
    MyCircularQueue(int = 10);
    ~MyCircularQueue();
    void print();
    int size() const;
    void printDetail() const;
}

