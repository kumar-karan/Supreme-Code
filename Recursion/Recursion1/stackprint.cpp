#include<iostream>
using namespace std;

void printReverse(int n)
{
    if(n==0)
    return;

    cout<<n<<" ";

    printReverse(n-1);
}

int main()
{
    int n;
    cout << "Enter tha value of n : ";
    cin>>n;
    printReverse(n);
    
    return 0;
}