
#include<iostream>
#include<stack>

using namespace std;

//s.push -> insertion
//s.pop -> deletion
//s.top() -> seek

int main()
{
    //creation
    stack<int> st;

    //insertion
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout << "Element on top is : "<< st.top() <<endl;

    cout << "Size of Stack is :" << st.size() << endl;

    if(st.empty())
        cout <<"Stack is Empty" << endl;
    else
        cout <<"Stack is not empty" << endl;
   
    return 0;
}