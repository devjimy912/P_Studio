#ifndef MYCIRCULARQUEUE_H
#define MYCIRCULARQUEUE_H

#include <iostream>

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

#endif