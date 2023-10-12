#include "queue.hpp"

Queue::Queue(int size)
{
    this->size = size;
    this->arr = new char[size];
    this->rear = -1;
    this->front = -1;
}

void Queue::enqueue(char ch)
{
    if (isFull())
    {
        return; 
    }

    if (front == -1)
    {
        front = 0;
    }

    rear = (rear + 1) % size;
    arr[rear] = ch;
}

char Queue::dequeue()
{
    if (isEmpty())
        return '\0';

    char data = arr[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        front = (front + 1) % size; 

    return data;
}

bool Queue::isFull()
{
    return (front == (rear + 1) % size);
}

bool Queue::isEmpty()
{
    return (front == -1);
}
