#include<iostream>
using namespace std;

class doublyQueue
{
    public:
    int*arr;
    int size;
    int front,rear;

    doublyQueue(int size)
    {
        this-> size = size;
        arr = new int[size];
        front = rear = -1;
    }

    void pushRear(int data)
    {
        if(front == 0 && rear == size-1 && (rear+1) % size == front)
            cout << "Q is full, cannot insert"<< endl;
        else if(front == -1 && rear == -1)
        {
            front = rear =0;
            arr[rear] = data;
        }
        else if(rear == size -1 && front !=0)
        {
            rear =0;
            arr[rear] = data;
        }
        else
        {
            rear++;
            arr[rear] = data;
        }

    }

    void pushFront(int data)
    {

        if(front == 0 && rear == size-1 && (rear+1) % size == front)
            cout << "Q is full, cannot insert"<< endl;
        else if(front == -1 && rear == -1)
        {
            front = rear =0;
            arr[front] = data;
        }
        else if( front ==0 && rear != size -1)
        {
            front = size-1;
            arr[front] = data;
        }
        else
        {
            front--;
            arr[front] = data;
        }


    }

    void popFront()
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

    void popRear()
    {
        // Empty 
        if(front ==-1 && rear == -1)
            cout<< "Q is empty, cannot pop " << endl;
        // single element
        else if(front == rear)
        {
            arr[rear] = -1;
            front = rear =-1;
        }
        //circular nature
        else if(rear == 0)
            rear = size-1;
        // natural flow   
        else
            rear--;


    }

};

int main()
{
    
    return 0;
}