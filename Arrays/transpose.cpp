#include<bits/stdc++.h>
using namespace std;

void transpose(int arr[][3],int b[][3], int m,int n)
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            b[i][j]= arr[j][i]; 
        }
    }
}

int main ()
{
    int n,m;
    int arr[3][3];
    int b[3][3];
    cin >> m >> n;


    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>> arr[i][j];
        }
    }

    transpose(arr,b,m,n);
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<< b[i][j] << " ";
        }
        cout<<endl;
    }


}