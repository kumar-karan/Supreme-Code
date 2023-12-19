#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int m,n;

    cin>>m>>n;

    for(int i=0; i<m; i++)
    {
        if(i==0 || i==m-1)
        {
            for(int j=0; j<n; j++)
            {
                cout << "* ";
            }
        }
        else
        {
            cout<<"* ";
            for(int j=0; j<n-2; j++)
            {
                cout<<"  ";
            }
            cout<<"* ";
        }
    
        cout<<endl;

    }
}