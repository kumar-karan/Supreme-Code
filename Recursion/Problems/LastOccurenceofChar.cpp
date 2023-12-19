#include<iostream>
using namespace std;

// string -> abcddefg (7)
// char(x) -> d; whats its last occurence (6)

/*
* Search Left to right 
* Search Right to left
*/

int lastOccurence(string str, char ch, int i)
{
    if(ch == str[i])
        return i;
    if(i<0)
        return -1;

    return lastOccurence(str, ch, i-1);
}

int main()
{ 
    string str = "abcddedg";

    char ch = 'd';
    int i =str.size()-1;
    int last = lastOccurence(str, ch, i);
    cout << last <<endl;
    
    return 0;
}