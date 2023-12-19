#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> prevSmallerElement(vector<int>& input)
{
    vector<int> ans(input.size());
    stack<int> s;
    s.push(-1);

    for(int i=0; i< input.size(); i++)
    {
        int curr = input[i];

        while(s.top() >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }

    return ans;
} 

void print(vector <int> ans)
{
    for(int i=0; i<ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{

    vector<int> input;
    input.push_back(2);
    input.push_back(1);
    input.push_back(4);
    input.push_back(3);

    print(input);
    vector<int> ans1 = prevSmallerElement(input);
    print(ans1);
    // vector<int> ans2 = nextSmallerElement(input);
    // print(ans2);
    
    return 0;
}