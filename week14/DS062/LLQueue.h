#ifndef LLQUEUE_H
#define LLQUEUE_H

class Node{
public:
    int data;
    Node *link;
    Node(const int& num){
        data = num;
        link = nullptr;
    }
};

class LLQueue{
private:
    Node *front;
    Node *rear;
public:
    LLQueue();
    ~LLQueue();
    void enqueue(const int& value);
    void dequeue();
    bool isEmpty() const;
    void showFront() const;
    void showRear() const;
    void print() const;
    void clear();
    int Rear() const;
    int RearP() const;
    int Front() const;
};

#endif