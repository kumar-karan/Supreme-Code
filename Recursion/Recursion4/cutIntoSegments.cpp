#include<iostream>
using namespace std;

/*
Maximum no. of segments you can make provided that each segment of length x,y,x.

*/

int solve(int n, int x, int y, int z)
{
    // base case 
    if(n == 0)
        return 0;

    if(n<0)
        return INT_MIN;    

    int ans1 = solve(n-x, x,y,z) +1;
    int ans2 = solve(n-y, x,y,z) +1;
    int ans3 = solve(n-z, x,y,z) +1;

    int ans = 0;

    ans = max(ans1, max(ans2, ans3));

    if(ans >= 0)
        return ans;
    else
        return 0;       
}

int main()
{
    int n = 7;
    int x = 5;
    int y = 2;
    int z = 2;

    int ans = solve(n,x,y,z);
    cout << "Answer is : "<< ans << endl;
    return 0;
}