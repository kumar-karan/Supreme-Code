#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main ()
{
    // vector<vector<int> > arr;

    // vector<int> a{1,2,3};
    // vector<int> b{2,4,6};
    // vector<int> c{1,3,7};

    // arr.push_back(a);
    // arr.push_back(b);
    // arr.push_back(c);

    // for(int i=0; i<arr.size(); i++)
    // {
    //     for(int j=0; j<arr[i].size(); j++)
    //     {
    //         cout << arr[i][j]<< " ";
    //     }
    //     cout<<endl;
    // }



    // type 2

    int row=3, col = 3;
    vector<vector<int> > arr(row, vector<int>(col, 0));
    for(int i=0; i<arr.size(); i++)
    {
        for(int j=0; j<arr[i].size(); j++)
        {
            cout << arr[i][j]<< " ";
        }
        cout<<endl;
    }


    vector<vector<int> > b(5,vector<int>(5,-8));
    for(int i=0; i<b.size(); i++)
    {
        for(int j=0; j<b[i].size(); j++)
        {
            cout << b[i][j]<< " ";
        }
        cout<<endl;
    }
}