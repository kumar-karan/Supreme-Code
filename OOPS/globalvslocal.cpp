#include<iostream>
using namespace std;
// most local ko zyada preference 
int x =4; // global
int main ()
{
    x = 20; // global
    int x = 40;
    cout << x << endl; // local
    cout << ::x << endl; // global

    {
        int x = 50;
        cout << x << endl;
        cout << :: x << endl;
        // cannot access 40 waala x idhar 
    }
     
}