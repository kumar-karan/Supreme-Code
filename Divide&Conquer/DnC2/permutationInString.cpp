#include<iostream>
using namespace std;

// ^ String ki Saari permutation return krke dedo
// ! har ek char har ek pos pe aana chahta hai 


void printPermutation(string &str, int i)
{

    // base case 
    if(i >= str.length())
    {
        cout<< str << " ";
        return;
    }

    // swapping
    for(int j=i; j< str.length(); j++)
        
    {
        swap(str[i], str[j]);

    //rec call
        printPermutation(str, i+1);

    //backtracking line
        swap(str[i], str[j]);
    }
}



int main()
{
    string str = "abc";
    // permutation(str);
    printPermutation(str,0);

    
    return 0;
}