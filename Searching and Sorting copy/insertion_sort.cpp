#include<bits/stdc++.h>
using namespace std;

// int min_element(vector<int> arr, int i)
// {
//     int min = arr[i];
//     int imin;
//     for(int m=0; m<arr.size(); m++)
//     {
//         if( min > arr[i])
//         {
//             min = arr[i];
//             imin = i;
//         }
//     }
//     return imin;
// }
void print(vector<int> arr, int n)
{
    for(int i=0; i<n; i++)
    {
        cout << arr[i]<< " ";
    }
    cout << endl;
}
void insertion_sort(vector<int> arr, int n)
{
    for(int i=0; i<n-1; i++)
    {
        int minIndex = i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j]< arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
    print(arr,n);
}

int main ()
{
    vector<int> arr{5,4,3,2,1};
    int n = arr.size();
    insertion_sort(arr,n);
    
}