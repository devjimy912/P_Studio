#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = nullptr;
    }
};

class MyStackIntList {
private:
    Node* stackTop;      // top element, head

public:
    void initialize();
    int getNodeCnt() const;
    MyStackIntList();    // constructor to make the stack 
    ~MyStackIntList();   // Destructor to remove from memory 
    void push(const int& item);   // push function for inserting an element at the top of stack
    void pop();          // pop function for deleting the topmost element
    bool isEmpty() const;      // check either stack is empty or not
    void printAll();     // function for displaying the stack 
    int top() const;     // top function for checking the topmost element present in the stack 
};


