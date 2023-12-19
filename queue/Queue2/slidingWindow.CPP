#include<iostream>
#include<deque>
using namespace std;
/*
* First -ve integer in every window of size k
~ [12 -1 -7 8 -15 30 16 28]
k=3

Ek window se doosre window pe jaane ke liye
front se pop karenge and rear se push karenge
*/

void solve(int arr[], int size, int k)
{
    deque<int> q;

    // process first window of size k
    for(int i=0; i<k; i++)
    {
        if(arr[i] < 0)
        {
            q.push_back(i);
        }
    }

    // remaining window ko process krna

    for(int i=k; i<size; i++)
    {
        // ans dedo purani window ka
        if(q.empty())
        {
            cout << 0 <<" ";
        }
        else
            cout << arr[q.front()] <<" ";

        // out of window elements ko remove krdo 
        while((!q.empty())&&(i-q.front() >= k))
        {
            q.pop_front();
        }
        // check current element for insertion
        if(arr[i] < 0)
        {
            q.push_back(i);
        }
    }
    if(q.empty())
        cout << 0 <<" ";
    else
        cout << arr[q.front()] <<" ";


}

int main()
{
    int arr[] ={12, -1, -7, 8, -15, 30, 16, 28};
    int size = 8;

    int k=3;

    solve(arr,size,k);

    
    return 0;
}