#include<iostream>
using namespace std;

/*
array diya hai, target sum diya hai 
kitne min no of element to reach target
*/

// ! COIN CHANGE PROBLEM

// mini bhi pass karenge to count min no. of elements

int solve (vector<int> & v, int target)
{
    if(target == 0)
        return 0;
    if(target < 0)
        return INT_MAX;

    // Lets solve one case 
    int mini = INT_MAX;
    for(int i =0; i< v.size(); i++)
    {
        int ans = solve(v, target - v[i]);
        if(ans!= INT_MAX)
        mini = min(mini, ans + 1);
    }

    return mini;
}


int main()
{
    vector<int> v{1,2};
    int target = 5;
    int ans = solve(v, target);
    cout << "Answer is : "<< ans << endl;
    return 0;
} 