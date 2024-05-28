#include <iostream>
using namespace std;

template<typename T>
class MyStack {
private: 
    int size;   // size of the Stack
    int top;    // index of top element
    T* list;     // Stack Pointer (int array) 
public:
    MyStack(int size);    // constructor to make the Stack with size 
    ~MyStack();           // Destructor to remove from memory 
    void push(T x);   // push function for inserting an element at the top of Stack
    T pop();          // pop function for deleting the topmost element
    bool isFull();       // check either the Stack is full or not
    bool isEmpty();      // check either Stack is empty or not
    void display();     // function for displaying the Stack 
    T stackTop();     // top function for checking the topmost element present in the Stack 
};


