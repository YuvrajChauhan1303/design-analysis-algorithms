#include "queue.hpp"

//Function Declaration for Queue

Queue::Queue(int size)
{
    this->size = size;
    this->arr = new char[size];
    this->rear = -1;
    this->front = -1;
}

void Queue::enqueue(int num)
{
    if(isFull())
        return;

    if (front == -1) 
    {
        front = rear = 0;
        arr[rear] = num;
    }
 
    else if (rear == size-1 && front != 0)
    {
        rear = 0;
        arr[rear] = num;
    }
 
    else
        arr[++rear] = num;
}

char Queue::dequeue()
{
    if(isEmpty())
        return '0';

    char data = arr[front--];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size-1)
        front = 0;
    else
        front++;
 
    return data;
}

bool Queue::isFull()
{
    return (front == 0 && rear == size-1) || ((rear+1) % size == front);
}

bool Queue::isEmpty()
{
    return (front == -1);
}