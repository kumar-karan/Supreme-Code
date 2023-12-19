#include<iostream>
#include<stack>
using namespace std;

bool validParenthesis (string s)
{
    stack<char> st;
    for(int i=0; i< s.length(); i++)
    {
        char ch = s[i];

        if(ch == '{' || ch == '(' || ch == '[')
        {
            st.push(ch);
        }
        else
        { // closing Bracket 
            if(!st.empty())
            {
                char topCh = st.top();
                if(ch == ')' && topCh == '(')
                {
                    st.pop();
                }
                else if(ch == '}' && topCh == '{')
                {
                    st.pop();
                }
                else if(ch == ']' && topCh == '[')
                {
                    st.pop();
                }
                else 
                {
                    // brackets not matching
                    return false;
                }
            }
            else
            {
                return false;
            }

        }

        
    }

    if(st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    

    return 0;
}