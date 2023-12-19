/*
What is a subsequence 
String me se kuch char ko include exclude kiya but ordering same rkhi 
! 2^n subsequences 
*abc
1. abc
2. ab
3. a
4. bc
5. b
6. c
7. ac
8. _ 

!Pick NOT PICK PATTERN OR INCLUDE EXCLUDE PATTERN
*/

#include<iostream>
using namespace std;



vector<string> printSubsequences(string str, string output, int i,vector<string> &v)
{
    if(i>= str.length())
    {
        // cout << output << endl;
        v.push_back(output);
        return v;
    }

    //excludes

    printSubsequences(str, output, i+1,v);
    
    //include
    output.push_back(str[i]);
    // output = output + str[i];
    printSubsequences(str, output, i+1,v);
    return v;
}

#include<iostream>
using namespace std;

int main()
{
    string str = "abc";
    string output = "";
    vector<string> v;

    int i=0;
    printSubsequences(str, output, i, v);

    cout <<"Printing all subsequences " << endl;
    for(auto val: v)
    {
        cout << val <<" ";
    }
    return 0;
}