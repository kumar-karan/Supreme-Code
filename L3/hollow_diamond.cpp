#include<bits/stdc++.h>
using namespace std;







int main ()
{
    int n;

    cin>>n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            cout<<" ";
        }

        for(int j=0; j< 2*i+1; j++)
        {
            if(j==0 || j== 2*i)
                cout<<"*";
            else
                cout<< " ";
        }

        for(int j=0; j<i; j++)
        {
            cout<< " ";
        }

        for(int j=0; j< 2*n - 2*i -1 ; j++)
        {
            if(j==0 || j== 2*n - 2*i - 2)
                cout<<"*";
            else
                cout<< " ";
        }

        // for(int j=0; j<i+1; j++)
        // {
        //     if( j==0 || j== i)
        //     {
        //         cout<<"* ";
        //     }
        //     else
        //     {
        //         // cout<<"* ";
        //         // for(int j=0; j<i+1-2; j++)
        //         // {
        //         //     cout<<
        //         // }
        //         cout<<"  ";
                
        //     }
        // }

        cout<<endl;


    }
}