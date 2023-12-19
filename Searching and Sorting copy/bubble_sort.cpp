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
    vector<int> arr{10,1,7,6,14,9};
    int n = arr.size();
    cout<< n<<endl;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
        
        }
    }
    print(arr,n);

}