#include "stackInt.h"
#include <iostream>
using namespace std;

template<typename T>
MyStack<T>::MyStack(int size) { 
    S = new T[size]; // creating the size of the Stack in memory 
    this->size = size; 
    top = -1; // intially set top of the Stack as -1;
}

template<typename T>
MyStack<T>::~MyStack() {
    delete[] list; // free the memory 
}

template<typename T>
void MyStack<T>::push(T x) {
    if (isFull()) { 
        cout << "Stack Overflow!" << endl; 
    }
    else {  
        top++; // increment top 
        list[top] = x; // and push the element to Stack 
    }
}

template<typename T>
T MyStack<T>::pop() { 
    // int x = -1; // initially setting x as -1 
    if (isEmpty()) { 
        cout << "Stack Underflow!" << endl; 
    }
    else {
        // x = S[top]; // take out the element 
        // top--; // and decreament the size of the Stack 
        return list[top--];
    }
    // return x;
}

template<typename T>
bool MyStack<T>::isFull() { 
    if (top == size - 1) { 
        return true;
    }
    return false;
}

template<typename T>
bool MyStack<T>::isEmpty() {
    if (top == -1) {
        return true;
    }
    return false;
}

template<typename T>
void MyStack<T>::display() { 
    cout << "Stack ("<< size << ") : ";
    for (int i = top; i >= 0; i--) {
        cout << S[i] << " | " << flush;
    }
    cout << endl;
}

template<typename T>
T MyStack<T>::stackTop() {
    if (isEmpty()) {
        return -1;
    }
    return list[top];
}