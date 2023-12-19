#include<iostream>
using namespace std;

int factorial(int n)
{
    if(n ==0 || n== 1)
        return 1;
    
    return n*factorial(n-1);
}

int main()
{
    int n;
    cout << "Enter tha value of n :";
    cin>>n;
    int ans = factorial (n);

    cout << "Answer is : " << ans;
    return 0;
}