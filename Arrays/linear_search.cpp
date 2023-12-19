#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int n,m,k;
    int arr[10][10];
    cin >> m >> n >>k;


    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>> arr[i][j];
        }
    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(arr[i][j] == k)
            {
                cout << " Found at index : " << i <<","<< j <<endl;
                break;
            }
            // else 
            //     cout<<" Not found " <<endl;
        }
    }



}