#include<iostream>
using namespace std;

int BinarySearch(int arr[], int n, int key)
{
    int s=0;
    int e = n-1;
    int mid = (s+e)/2;

    while(s>=e)
    {
        if(arr[mid] == key)
            return mid;
        if(arr[mid] < key)
            s = mid+1;
        else
            e = mid -1;
        mid = (s+e)/2; 
    }
}

int binarySearchRecursion(vector<int> &arr, int s, int e, int key )
{
    //base case 
    int mid = (s+e)/2;
// key not found
// s> e means invalid array
    if(s>e)
        return -1;
// key found
    if(arr[mid] == key)
        return mid;
    if(arr[mid] > key)
        return binarySearchRecursion(arr,s, mid-1, key);
    else //if (arr[mid] < key)
        return binarySearchRecursion(arr, mid+1, e, key);
    
    return -1;
}

int main()

{
    vector<int> v{10,20,40,50,70,90,99};
    int target = 99;
    int n = v.size();
    int s =0, e = n-1;
    int ans = binarySearchRecursion(v,s,e,target);

    cout << "Answer is : " << ans << endl;
    
    return 0;
}