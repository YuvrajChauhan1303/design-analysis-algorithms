#include<iostream>

//Class Declaration for Queue
class Queue
{
    private:
        int size;
        int front;
        int rear;
        char * arr;

    public:
        Queue(int size);
        void enqueue(char ch);
        char dequeue();
        bool isFull();
        bool isEmpty();
};