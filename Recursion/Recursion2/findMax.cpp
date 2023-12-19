#include<iostream>
#include<array>

using namespace std;

void findMax(int arr[], int n, int &maxi)
{
    if(n == 0)
        return;

    maxi = max(maxi , arr[0]);

    findMax(arr+1, n-1, maxi);
}

void findMin (int arr[], int n, int& mini)
{
    if(n == 0)
        return;

    mini = min(mini, *arr);

    findMin(arr+1, n-1, mini);
}

int main()
{
    int arr[5] = {0, 20, 300, 40, 50};
    int n = 5;

    int maxi = INT_MIN;
    int mini = INT_MAX;
    
    findMax(arr,n, maxi);
    findMin(arr,n, mini);

    cout << "Max Value of Array is : "<< maxi << endl;
    cout << "Min Value of Array is : "<< mini;


    return 0;
}