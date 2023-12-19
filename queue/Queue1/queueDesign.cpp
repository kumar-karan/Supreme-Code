#include<iostream>
using namespace std;

class Queue
{
    public:
    int *arr;
    int size;
    int front, rear;

    Queue(int size)
    {
        this -> size = size;
        arr = new int[size];
        front = 0;
        rear =0;
    }

    void push(int data)
    {
        if(rear == size)
            cout << "Q is full" << endl;
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    void pop()
    {
        if(front == rear)
        {
            cout << "Q is empty" << endl;
        }
        else{
            arr[front] = -1;
            front ++;
            if(front == rear)
            {
                front = 0;
                rear =0;
            }
        }
    }

    int getFront()
    {
        if(front == rear)
        {

            cout << "Q is empty" << endl;
            return -1;
        }
        else
            return arr[front];
    }

    int getSize()
    {
        if(front == rear)
            return 0;
        return rear-front;
    }

    bool isEmpty()
    {
        if(front == rear)
            return true;
        else 
            return false;
    }

};

int main()
{
    Queue q(10);
    q.push(5);
    q.push(15);
    q.push(25);
    q.push(35);


    cout << " Size of Queue is : "<< q.getSize()<<endl;
    q.pop();
    cout << " Size of Queue is : "<< q.getSize()<<endl;

    cout << "Front Element is : " << q.getFront()<<endl;
    
    if(q.isEmpty())
        cout << "Queue is Empty"<< endl;
    else
        cout << "Queue is NOT Empty"<< endl;
    
    return 0;
}