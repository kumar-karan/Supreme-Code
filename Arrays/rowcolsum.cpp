#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int n,m;
    int arr[10][10];
    cin >> m >> n;


    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>> arr[i][j];
        }

    }
    for(int i=0; i<m; i++)
    {
        int sum=0;
        for(int j=0; j<n; j++)
        {
            sum+= arr[i][j];
        }
        cout<< " Sum of row "<<i<<" is "<< sum << endl;
    }

    for(int i=0; i<m; i++)
    {
        int sum=0;
        for(int j=0; j<n; j++)
        {
            sum+= arr[j][i];
        }
        cout<< " Sum of col "<<i<<" is "<< sum << endl;
    }

}