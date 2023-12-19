// ! MERGE SORT USING RECURSION 
/*
*   Divide And Conquer
*   7,3,2,16,24,4,11,9
    7,3,2,16,   24,4,11,9  

~ 1. Mid Find 
~ 2. Break into two half
~ 3. Recursion two half sort
~ 4. 2 Half merge

Q Merge two sorted arrays 
use two pointer approach

*/


#include<iostream>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = (s+e)/2;
    int len1 = mid - s+1;
    int len2 = e - mid;

    int* left = new int [len1]; // dynamic array 
    int* right= new int [len2];

    // copying values

    int k =s;
    for(int i = 0; i< len1; i++)
    {
        left[i] = arr[k];
        k++;
    }
    k = mid+1;
    for(int i = 0; i< len2; i++)
    {
        right[i] = arr[k];
        k++;
    }

    // merge logic 

    int leftIndex = 0;
    int rightIndex = 0;
    int mainIndex = s;

    while(leftIndex < len1 && rightIndex < len2)
    {
        if(left[leftIndex] < right[rightIndex])
        {
            arr[mainIndex] = left[leftIndex];
            mainIndex++; leftIndex++;
        }
        else
        {
            arr[mainIndex] = right[rightIndex];
            mainIndex++; rightIndex++;
        }

        

        //! TO DO -> DELETE LEFT AND RIGHT ARRAY 
        
    }

    while(leftIndex < len1)
    {
        arr[mainIndex++] = left[leftIndex++];
    }
    while(rightIndex < len2)
    {
        arr[mainIndex++] = right[rightIndex++];
    }

}

void mergeSort(int* arr, int s, int e)
{
    // base case
    if(s >= e)      // single element is always sorted
        return ;
    int mid = (s+e)/2;
    // left part sort krdo 
    mergeSort(arr, s, mid);

    // right part sort krdo 
    mergeSort(arr, mid+1, e);

    // Now merge two sorted arrays 
    merge(arr, s ,e);


}

int main()
{
    int arr[] = {4,5,13,2,12,6};

    // int n =5; 
    int n =sizeof(arr)/ sizeof(int);
    int s = 0, e = n-1;
    // for(int i=0; i<n;i++)
    //     cout<< arr[i] << " ";
    // cout <<endl;


    mergeSort(arr, s, e);

    for(int i=0; i<n; i++)
        cout<< arr[i] << " ";
    cout <<endl;

    return 0;
}