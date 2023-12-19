#include<iostream>
#include<queue>
#include<stack>

/*
Give First non repeating character in a Stream
* i/p -> a a b c
* o/p -> a # b b

* a a c
* a # c

* z a r c a a z r d
* z z z z z z r c c

! Queue is used to track the characters

*/


using namespace std;

int main()
{
    string str = "zarcaazrd";
    int freq[26] ={0};
    queue<char> q;

    string ans = "";

    for(int i=0; i< str.length(); i++)
    {
        char ch = str[i];

        //Increment frequency
        freq[ch-'a']++;

        q.push(ch);
        
        while(!q.empty())
        {
            if(freq[q.front() -'a'] > 1 )
            {
                q.pop();
            }
            else
            {
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty())
        {
            ans.push_back('#');

        }
    }
    cout <<"Final String : " << ans;

    
    return 0;
}