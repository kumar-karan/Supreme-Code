#include<iostream>
using namespace std;

class CircularQueue
{
    public:
    int size;
    int *arr;
    int front, rear;

    CircularQueue(int size)
    {
        this -> size = size;
        arr = new int[size];
        front =-1;
        rear =-1;
    }

    void push(int data)
    {
        //queue full
        if(front ==0 && rear == size-1 && (rear+1) % size == front)
        {
            cout<< "Q is full, cannot insert " << endl;
        }
        //first element
        else if(front == -1 && rear ==-1)
        {
            front = rear = 0;
            arr[rear] = data;
        }
        //circular nature
        else if(rear == size-1 && front!= 0)
        {
            rear =0;
            arr[rear] = data;
        }
        //normal flow
        else
        {
            rear++;
            arr[rear]= data; 
        }
    }

    void push2(int data)
    {
        // Check if the queue is full
        if ((rear + 1) % size == front)
        {
            cout << "Queue is full, cannot insert " << data << endl;
        }
        else
        {
            // If the queue is empty, initialize both front and rear
            if (front == -1 && rear == -1)
            {
                front = rear = 0;
            }
            else
            {
                // Move rear circularly
                rear = (rear + 1) % size;
            }

            // Insert data into the queue
            arr[rear] = data;
        }
    }

    void pop()
    {
        // Empty 
        if(front ==-1)
            cout<< "Q is empty, cannot pop " << endl;
        // single element
        else if(front == rear)
        {
            arr[front] = -1;
            front = rear =-1;
        }
        //circular nature
        else if(front == size-1)
            front = 0;
        // natural flow
        else
            front ++;
    }

};

int main()
{
    
    return 0;
}