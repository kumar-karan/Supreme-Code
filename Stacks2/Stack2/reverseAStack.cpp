#include<stack>
#include<iostream>
using namespace std;

// *we will insert one element at bottom and recursion will take care of rest 

void insertAtBottom(stack <int> &s, int target)
{
    if(s.empty())
    {
        s.push(target);
        return;
    }
    int topElement = s.top();
    s.pop();
    //rec call
    insertAtBottom(s,target);
    //BackTrack
    s.push(topElement);
}

void reverseStack(stack<int> &s)
{
    // base case 
    if(s.empty())
    {
        return;
    }
    int target = s.top();
    s.pop();

    //reverse Stack
    reverseStack(s);
    
    insertAtBottom(s,target);
}

int main()
{
    stack <int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    reverseStack(s);

    cout << "\nPrinting Top to Bottom" << endl;

    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
     
    
    return 0;
}