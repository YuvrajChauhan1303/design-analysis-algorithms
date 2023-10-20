#ifndef ARRAY
#define ARRAY

#include "header.hpp"

class array
{
private:
    int *arr;
    int size;
    int top;

public:
    array(int size);
    ~array();
    void push(int element);
    int pop();
    bool isFull() const;
    bool isEmpty() const;
};

array::array(int size)
{
    this->size = size;
    this->arr = new int[size];
    this->top = -1;
}

array::~array()
{
    delete[] arr;
}

void array::push(int element)
{
    if (isFull())
    {
        std::cout << "Stack is full. Cannot push element " << element << std::endl;
    }
    else
    {
        top++;
        arr[top] = element;
    }
}

int array::pop()
{
    if (isEmpty())
    {
        std::cout << "Stack is empty. Cannot pop an element." << std::endl;
        return -1;
    }
    else
    {
        int popped = arr[top];
        top--;
        return popped;
    }
}

bool array::isFull() const
{
    return top == size - 1;
}

bool array::isEmpty() const
{
    return top == -1;
}

#endif
