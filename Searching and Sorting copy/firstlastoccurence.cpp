#include<bits/stdc++.h>
#include <vector>
using namespace std;

int firstOccurence(vector<int> arr, int target)
{
    int s=0, e= arr.size()-1, mid= s + (e-s)/2;
    int ans = -1;

    while ( s<= e)
    {
        if (arr[mid] == target)
        {//ans store and left search
            ans = mid;
            e = mid-1;
        }
        else if( target > arr[mid])
        {// right search 
            s = mid+1;
        }
        else if(target < arr[mid])
        {// left search 
            e = mid-1;
        }

        mid= s + (e-s)/2;
    }
    return ans;

}
 
int lastOccurence(vector <int> arr, int target)
{
    int s = 0, e = arr.size()-1, mid = s + (e-s)/2;
    int ans = -1;

    while(s<=e)
    {
        if (arr[mid] == target) 
        {
            ans = mid;
            s = mid+1;
        }
        else if(target < arr[mid])
            e = mid-1;
        else if(target > arr[mid])
            s = mid+1;

        mid = s + (e-s)/2;
    }
    return ans;

}
int main ()
{
    vector<int> v{1,3,4,4,4,4,6,7};
    int target = 4;
    int indexOfFirstOcc = firstOccurence(v, target);
    int indexOflastOcc = lastOccurence(v, target);


    cout << "First Occurence is : " << indexOfFirstOcc<<endl;
    cout << "Last Occurence is : " << indexOflastOcc<<endl;

    // auto ans2  = lower_bound (v.begin(), v.end(), target);
    // cout << ans2;
    // auto ans3  = upper_bound (v.begin(), v.end(), target);
    // cout << ans3;

}