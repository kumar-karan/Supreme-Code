#include<bits/stdc++.h>
using namespace std;

void print(vector<int> arr, int n)
{
    for(int i=0; i<n; i++)
    {
        cout << arr[i]<< " ";
    }
    cout << endl;
}

int main ()
{
    vector<int> arr= {0, 10, 5, 2};
    int n = arr.size();
    int s =0, e = n-1, mid = s+ (e-s)/2;

    while( s <= e)
    {
        // if(arr[mid]> arr[mid+1] && arr[mid]> arr[mid-1])
        // {
        //     cout<<arr[mid];
        // }
        if( arr[mid]< arr[mid+1])
            s = mid +1;
        else
            e = mid;

        mid = s+ (e-s)/2;
    }

    cout<< arr[mid];
}