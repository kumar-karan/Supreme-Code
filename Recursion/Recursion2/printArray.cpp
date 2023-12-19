#include<iostream>
using namespace std;

void printArrayRecursion (int arr[], int n)
{
    if(n == 0)
        return;
    cout << *arr << " ";
    // cout << arr[0] << " ";
    printArrayRecursion(arr+1 , n-1);
    cout << endl;
}

void printArrayLoop(int *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int n=5;

    printArrayLoop(arr,n);
    printArrayRecursion(arr, n);    
    return 0;
}