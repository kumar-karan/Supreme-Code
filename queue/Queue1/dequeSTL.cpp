#include<iostream>
#include<deque>

using namespace std;

int main()
{
    deque<int> dq;

    dq.push_front(5);
    dq.push_front(10);
    dq.push_back(20);
    dq.push_back(30);

    cout << "Size : "<< dq.size() << endl;
    dq.pop_front();
    cout << "Size : "<< dq.size() << endl; 

    cout <<dq.back() << endl;
    cout <<dq.front() << endl;

    return 0;
}