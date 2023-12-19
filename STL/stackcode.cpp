#include<iostream>
#include<stack>
using namespace std;
void explainStack();

int main()
{
    explainStack();
    
    return 0;
}

void explainStack()
{
    stack<int> st;
    st.push(1); //{1}
    st.push(2); //{2,1}
    st.emplace(3); //{3,2,1}
    cout<<endl;

    cout<< st.top();
    cout<<endl;

    st.pop();

    cout<<st.top();
    cout<<endl;

    cout<< st.size();
    cout<<endl;

    cout << st.empty();
    cout<<endl;
}

