#include<iostream>
using namespace std;

// Gives possible number of ways to reach a stair N;

int climbStairs(int n)
{
    // base case
    // for n= 0 -> theres only one way to reach 0 
    // for 1 too
    if(n == 0 || n == 1)
        return 1;
    //processing and recursion case
    return climbStairs(n-1) + climbStairs(n-2);
}

int main()
{
    int n;
    cout << "Enter tha value of n : ";
    cin>>n;
    int ans = climbStairs(n);
    cout << ans;
    return 0;
}
