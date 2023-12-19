#include<iostream>
#include<stack>

using namespace std;

void insertSorted(stack<int> &s, int &target)
{
    if(s.empty())
    {
        s.push(target);
        return;
    }
    if(s.top() >= target)
    {
        s.push(target);
        return;
    }

    int topElement = s.top();
    s.pop();

    insertSorted(s,target);

    // BT 
    s.push(topElement);

}

void sortStack(stack <int> &s)
{
    if(s.empty())
        return;

    int target = s.top();
    s.pop();

    sortStack(s);

    insertSorted(s, target);
}

int main()
{
    stack<int> s;
    s.push(7);
    s.push(11);
    s.push(3);
    s.push(5);
    s.push(9);
    s.push(13);

    sortStack(s);

    cout << "\nPrinting Top to Bottom" << endl;

    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}