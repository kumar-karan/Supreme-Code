#include<iostream>
#include<queue>
#include<stack>

//* 1. First K elements Stack ME daal ke krdo 
    // * n- k elements ko pop karo and push krdo 

using namespace std;

void reverseKQueue(queue<int> &q, int n)
{
    int size = q.size();
    stack<int> s;
    if(n==0 || n > size)
        return;
    for(int i=0; i< n; i++)
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

    for(int i =0; i<q.size()-n; i++)
    {
        int el = q.front();
        q.pop();
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


int main()
{
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);
    int l;
    cin >>l;
    printQueue(q);
    reverseKQueue(q, l);
    // reverseQueue(q);
    printQueue(q);
    
    return 0;
}