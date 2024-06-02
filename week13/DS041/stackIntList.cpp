#include "stackIntList.h"
#include <iostream>
using namespace std;

/*

*/

void MyStackIntList::initialize(){
    ~MyStackIntList();
    stackTop = nullptr;
}

int MyStackIntList::getNodeCnt() const{
    int count = 0;
    Node* curr = head;
    while(curr->next != nullptr){
        count++;
        curr = curr->next;
    }
    return count;
}

MyStackIntList::MyStackIntList() { 
    top = nullptr; // intially set top of the Stack as nullptr;
}

MyStackIntList::~MyStackIntList() {
    Node* p = top;
    while (top) {
        delete p;
        top = top->next;
        p = top;
    }
}

void MyStackIntList::push(const int& item) {
    Node* p = new Node;
    p->next = stackTop;
    stackTop = p;
    p->data = item;
}

int MyStackIntList::pop() { 
    int d = stackTop->data;
    Node* p = stackTop;
    stackTop = stackTop->next
    delete p;
    return d;
}

bool MyStackIntList::isEmpty() const{
    return top ? false : true;
}

void MyStackIntList::printAll(){
    if(head){
        cout << "Stack is empty" << endl;
        return;
    }
    Node* curr = head;
    while(curr){
        cout << curr->data;
        if(curr->next){
            cout << " -> ";
        }
    }
    cout << " (" << getNodeCnt() << " nodes)" << endl;
}

int MyStackIntList::top() const{
    if (stackTop)
        return stackTop->data;
    else
        return -1;
}

