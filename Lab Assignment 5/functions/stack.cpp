#ifndef STACK
#define STACK

#include "header.hpp"

class Stack {
private:
    int* data;
    int top;
    int size;

public:
    Stack(int maxSize);
    bool isEmpty() const;
    bool isFull() const;
    void push(int value);
    int pop();
};

Stack::Stack(int maxSize) {
    size = maxSize;
    data = new int[size];
    top = -1;
}

bool Stack::isEmpty() const {
    return top == -1;
}

bool Stack::isFull() const {
    return top == size - 1;
}

void Stack::push(int value) {
    if (isFull()) {
        std::cout << "Stack is full. Cannot push." << std::endl;
        return;
    }
    data[++top] = value;
}

int Stack::pop() {
    if (isEmpty()) {
        std::cout << "Stack is empty. Cannot pop." << std::endl;
        return -1;
    }
    return data[top--];
}

#endif // STACK
