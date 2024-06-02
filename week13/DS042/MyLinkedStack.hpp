#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Node {
public:
    int data;
    Node* next;
    
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class MyLinkedStack {
private:
    Node* stacktop;

public:
    MyLinkedStack() {
        stacktop = nullptr;
    }

    ~MyLinkedStack() {
        clear();
    }

    void initialize() {
        clear();
    }

    bool isEmpty() const {
        return stacktop == nullptr;
    }

    void push(const int& data) {
        Node* newNode = new Node(data);
        newNode->next = stacktop;
        stacktop = newNode;
    }

    void pop() {
        if (isEmpty()) return;
        Node* temp = stacktop;
        stacktop = stacktop->next;
        delete temp;
    }

    int top() const {
        if (isEmpty()) throw std::out_of_range("Stack is empty");
        return stacktop->data;
    }

    int getNodeCnt() const {
        int count = 0;
        Node* current = stacktop;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void printAll() const {
        Node* current = stacktop;
        while (current != nullptr) {
            std::cout << current->data;
            if (current->next != nullptr) std::cout << " -> ";
            current = current->next;
        }
        std::cout << " (" << getNodeCnt() << " nodes)" << std::endl;
    }

    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }
};
