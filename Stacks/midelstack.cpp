#include<bits/stdc++.h>
#include<stack>
using namespace std;

void printMiddle(stack<int> &s, int &totalSize)
{
    if(s.size() == totalSize/2 +1)
    {
        cout<< " Middle Element is: "<<s.top()<<endl;
    }
}
int main ()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);

    printMiddle(s, s.size());

    
    return 0;

}