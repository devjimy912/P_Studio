#include <iostream>
#include "Stack.h"

int main(){
    Stack<int> stack(5);

    stack.push(1);
    stack.push(2);
    stack.push(3);

    stack.print();

    return 0;
}