#include<iostream>
#include<queue>
#include<stack>

/* 
*1. Seperate two halves using two new queue
*2. First half ko ek new queue me rkhdo 

*/
using namespace std;

void interleaveQueue (queue<int> &q)
{
    int n= q.size();
    if(n ==0)
        return;
    int k = n/2;

    queue<int> q1;
    for(int i=0; i< k; i++)
    {
        int el = q.front();
        q.pop();
        q1.push(el);
    }

    //* Step 2 : Interleaving start krdo 

    while(!q.empty() && !q1.empty())
    {
        int first = q1.front();
        q1.pop();
        q.push(first);
        int second = q.front();
        q.pop();
        q.push(second);
    }
    if(n&1)
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
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    // q.push(10);

    printQueue(q);
    interleaveQueue (q);
    printQueue(q);

    return 0;
}