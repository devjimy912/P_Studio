#ifndef STACK_H
#define STACK_H

//Umm..

#include <iostream>

template <typename T>
class Stack { // Stack class implements StackInterface<T>
    private:
        T* list;
        int maxSize;
        int top;

    public:
        Stack(int max_stack_size);
        ~Stack();
        void push(T item);
        T pop();
        bool isEmpty() const;
        bool isFull() const;
        void initialize();
        void print();
};

//Constructor
template <typename T>
Stack<T>::Stack(int max_stack_size) {
    // implement
    maxSize = max_stack_size;
    top = -1;
    list = new T[max_stack_size];
}

//Destructor
template <typename T>
Stack<T>::~Stack() {
    // implement
    delete[] list;
}

template <typename T>
void Stack<T>::push(T item) {
    // implement
    if(top == maxSize-1){
        // std::cout << "Stack overflow" << std::endl;
    }else{
        list[++top] = item;
    }
}

template <typename T>
T Stack<T>::pop() {
    // implement
    if(top==-1){
        //이거 널포인터로 업그레이드 해야할지도..
        return 0;
    }else{
        return list[top--];
    }
}

template <typename T>
bool Stack<T>::isEmpty() const {
    // implement
    if(top < 0){
        // std::cout << "Stack underflow" << std::endl;
        return true;
    }else{
        return false;
    }
}

template <typename T>
bool Stack<T>::isFull() const {
    // implement
    return (top+1 == maxSize);
}

template <typename T>
inline void Stack<T>::initialize(){

}

template <typename T>
inline void Stack<T>::print(){
    Stack<T> dummy(maxSize);
    T temp;
    while(!isEmpty()){
        dummy.push(pop());
    }
    while(!dummy.isEmpty()){
        temp = dummy.pop();
        std::cout << temp << std::endl;
        push(temp);
    }
}

#endif
