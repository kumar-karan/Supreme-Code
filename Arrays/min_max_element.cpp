#include<bits/stdc++.h>
using namespace std;
// #define N 3;

int minelement(int arr[][3], int m, int n)
{
    // int min = arr[0][0];
    int min = INT_MAX;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if( arr[i][j] < min )
            {
                min = arr[i][j];
            }
        }
    }

    return min;
}

int maxelement(int arr[][3], int m, int n)
{
    // int max = arr[0][0];
    int max = INT_MIN;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if( arr[i][j] > max )
            {
                max = arr[i][j];
            }
        }
    }

    return max;
}

int main ()
{
    int n,m;
    int arr[3][3];
    cin >> m >> n;


    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>> arr[i][j];
        }
    }

    cout <<" Minimum element : " << minelement(arr, m,n)<<endl;
    cout <<" Maximum element : " << maxelement(arr, m,n)<<endl;


}