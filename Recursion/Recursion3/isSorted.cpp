#include<iostream>
using namespace std;

bool isSorted(vector<int> &v,int i, int &n)
{
    // base case
    if(i == n-1)
        return true;
    if(v[i+1] < v[i])
        return false;

    return isSorted(v,i+1,n);
}

int main()
{
    
    vector<int> v{20,30,50,60, 10};
    int n = v.size();
    int i =0;
    cout << isSorted(v, i, n)<<endl;
    return 0;
}