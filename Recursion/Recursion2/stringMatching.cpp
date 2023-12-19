#include<iostream>
using namespace std;

bool checkKey(string &str,int i, int &n, char &key)
{
    // null character se base case nikaal skte hai 
    if(i>= n )
    {
        //key not found 
        return false;
    }
    // 1 case solve krdo 

    if(str[i] == key)
        return true;
    
    return checkKey(str, i+1, n, key);

}

void checkKey1(string &str,int i, int &n, char &key, vector<int> &v)
{
    // null character se base case nikaal skte hai 
    if(i>= n )
    {
        //key not found 
        return;
    }
    // 1 case solve krdo 

    if(str[i] == key)
        // return i;
        v.push_back(i);
    
    return checkKey1(str, i+1, n, key, v);

}

void checkKeyCount(string &str,int i, int &n, char &key, int &count )
{
    // null character se base case nikaal skte hai 
    if(i>= n )
    {
        //key not found 
        return;
    }
    // 1 case solve krdo 

    if(str[i] == key)
        // return i;
        count++;
    
    checkKeyCount(str, i+1, n, key, count);

}

int main()
{
    string str = "lovebabbar";

    int n = str.length();
    char key = 'b';

    int i =0;

    vector<int> v;
    int count =0;
    checkKeyCount(str,i, n, key, count);
    // cout << "Ans is : "<< ans << endl;
    cout << "Printing ANSWER Vector" << endl;


    // for(auto i: v)
    // {
    //     cout << i << " ";
    // }
    cout <<count << endl;
    return 0;
}