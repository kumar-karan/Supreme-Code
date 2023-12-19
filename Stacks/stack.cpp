#include<bits/stdc++.h>
#include <stack>
using namespace std;

int main ()
{
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    st.pop();
    
    cout<<"Top: "<< st.top()<<endl;

    cout<<"Size:"<< st.size()<<endl;

    if(st.empty())
    {
        cout<<"Stack is empty"<<endl;
    }
    else
        cout<<"Stack is NOT empty"<<endl;


    return 0;
  
}