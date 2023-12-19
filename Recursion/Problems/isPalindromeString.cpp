#include<iostream>
using namespace std;

bool isPalindrome(string str, int i, int e)
{
    if(i>=e)
        return true;
    
    if(str[i] != str[e])
        return false;

    return isPalindrome(str, i+1, e-1);


}

int main()
{
    string str = "racecar";
    // cin >> str;

    if(isPalindrome(str, 0, str.size()-1))
        cout << "Palindrome";
    else 
        cout << "NOT a palindrome";
    
    return 0;
}