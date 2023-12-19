#include<bits/stdc++.h>
#include<vector>
using namespace std;


int binarysearch(int arr[],int n,int k)
{
    int s=0, e=n-1, mid = s+(e-s)/2;

    while(s<=e)
    {
        int element = arr[mid];

        if(element == k)
            return mid;
        else if(k < element)
            e = mid -1;
        else
            s = mid+1;
        mid = s+(e-s)/2; 
    }
    return -1;
}

int main ()
{
    int n,k;
    cin>>n>>k;

    int arr[n];
    for(int i =0; i<n; i++)
    {
        cin>>arr[i];
    }

    cout << binarysearch(arr,n,k);

// inbuilt function binary_search
    vector<int> v{ 1,2,3,4,5,6};
    if(binary_search ( v.begin(), v.end(), 10))
        cout<<"Found"<<endl;
    else
        cout<< "Not found"<<endl;


if(binary_search ( arr, arr + n, 10))
        cout<<"Found"<<endl;
    else
        cout<< "Not found"<<endl;
    


}