#ifndef QUEUE
#define QUEUE

#include "header.hpp"

class queue
{
private:
    vertex **data;
    int front;
    int rear;
    int size;

public:
    queue(int maxSize);
    bool isEmpty() const;
    bool isFull() const;
    void enqueue(vertex *value);
    vertex *dequeue();
};

queue::queue(int maxSize)
{
    size = maxSize + 1;
    data = new vertex *[size];
    front = 0;
    rear = 0;
}

bool queue::isEmpty() const
{
    return front == rear;
}

bool queue::isFull() const
{
    return (rear + 1) % size == front;
}

void queue::enqueue(vertex *value)
{
    if (isFull())
    {
        std::cout << "queue is full. Cannot enqueue." << std::endl;
        return;
    }
    data[rear] = value;
    rear = (rear + 1) % size;
}

vertex *queue::dequeue()
{
    if (isEmpty())
    {
        std::cout << "queue is empty. Cannot dequeue." << std::endl;
        return nullptr;
    }
    vertex *value = data[front];
    front = (front + 1) % size;
    return value;
}

#endif // QUEUE
