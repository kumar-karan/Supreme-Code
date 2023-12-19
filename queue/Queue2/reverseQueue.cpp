#include<iostream>
#include<stack>
#include<queue>

using namespace std;

//* 1. Stack use krskte.
//* 2. Recursion se krskte 

void reverseQueue(queue<int> &q)
{
    stack<int> s;

    while(!q.empty())
    {
        int el = q.front();
        q.pop();
        s.push(el);
    }

    while(!s.empty())
    {
        int el = s.top();
        s.pop();
        q.push(el);
    }

}

void printQueue(queue<int> q)
{
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
        cout << endl;
}

void reverseQueueRecursion(queue<int> &q)
{
    if(q.empty())
        return;

    int temp = q.front();
    q.pop();

    reverseQueueRecursion(q);
    q.push(temp);
}

int main()
{
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    printQueue(q);
    reverseQueueRecursion(q);
    // reverseQueue(q);
    printQueue(q);
    
    return 0;
}