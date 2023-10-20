#ifndef STACK
#define STACK

#include "header.hpp"

class stack {
private:
    vertex** data; 
    int top;
    int size;

public:
    stack(int maxSize);
    bool isEmpty() const;
    bool isFull() const;
    void push(vertex* value); 
    vertex* pop();
};

stack::stack(int maxSize) {
    size = maxSize;
    data = new vertex*[size];
    top = -1;
}

bool stack::isEmpty() const {
    return top == -1;
}

bool stack::isFull() const {
    return top == size - 1;
}

void stack::push(vertex* value) {
    if (isFull()) {
        std::cout << "Stack is full. Cannot push." << std::endl;
        return;
    }
    data[++top] = value;
}

vertex* stack::pop() {
    if (isEmpty()) {
        std::cout << "Stack is empty. Cannot pop." << std::endl;
        return nullptr;
    }
    return data[top--];
}

#endif // STACK
