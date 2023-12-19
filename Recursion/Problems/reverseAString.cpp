#include<iostream>
#include<string.h>
using namespace std;

void reverseString(string &str, int i,int e)
{
    if(i > e)
        return ;
    swap(str[i], str[e]);


    return reverseString(str, i+1 ,e-1);
}

int main()
{
    string str;
    cin >> str;
    reverseString(str, 0, str.size()-1);
    cout << str;
    
    return 0;
}