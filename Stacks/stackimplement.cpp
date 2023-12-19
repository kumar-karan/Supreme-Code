#include<bits/stdc++.h>
using namespace std;

class Stack
{
    public:

    int top;
    int *arr;
    int size;

    Stack(int size)
    {
        arr = new int[size];
        this -> size = size;
        top = -1;
    }

    //functions

    void push(int data)
    {
        if(size - top >1)
        {
            top ++;
            arr[top] = data;
        }
        else
            cout<< "Stack Overflow" << endl;


    }
    void pop()
    {
        if(top == -1 )
            cout<< " Stack Underflow, Cant delete element"<<endl;
        else
            top-- ;
    }
    int getTop()
    {
        if(top == -1)
            cout<< " Stack Underflow"<<endl;
        else
            return arr[top];
    }
    int getSize()
    {
        return top+1;
    }

    bool isEmpty()
    {
        if(top == -1)
            return true;
        else 
            return false;
    }


};

int main ()
{

    Stack s(10);

    s.push(10);
    s.push(20);
    s.push(30);

    while(!s.isEmpty())
    {
        cout<<s.getTop() << " ";
        s.pop();
    }

    cout<< endl; 
    cout<< " Size of Stack " << s.getSize()<< endl;

    return 0;

     
}