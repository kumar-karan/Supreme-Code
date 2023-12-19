#include<iostream>
#include<stack>
using namespace std;

void printMiddle(stack<int> &s, int &totalSize)
{
    if(s.size() == 0)
    {
        cout<< " There is no element is Stack" << endl;
        return;
    }

    if(s.size() == totalSize/2 +1)
    {
        cout << "Middle Element is : "<< s.top() <<endl;
        return;
    }

    int temp = s.top();
    s.pop();

    printMiddle(s,totalSize);

    s.push(temp);
}

int main()
{
    //total size /2 + 1 == size
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);

    int totalSize = s.size();

    printMiddle(s,totalSize);

    return 0;
}