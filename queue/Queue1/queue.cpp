#include<iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;

    q.push(5); // popped
    q.push(15);
    q.push(25);
    q.push(35);
    q.push(45);
    q.push(55);

    cout << "Size of Queue : "<< q.size() <<endl;
    q.pop();
    cout << "Size of Queue after pop : "<< q.size() <<endl;

    if(q.empty())
        cout << "Queue is Empty"<< endl;
    else
        cout << "Queue is NOT Empty"<< endl;

    cout << "Front Element is : " << q.front()<<endl;
    return 0;
}