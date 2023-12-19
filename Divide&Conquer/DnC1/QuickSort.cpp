#include<iostream>
using namespace std;
/*
! Pivot Element
    * Pivot Element ko shi place pe daalo -> count elements smaller than piv el
! Recursion calls 


~ BEST AND Average -> O(nlogn) -> logn time partition krna pdta hai, n time complexity hai partition ki 
~ Worst (Reverse Sorted) -> O(n^2)

*/

int partition(int arr[], int s, int e)
{
    // 1. Choose pivot element
    int pivotIndex = s;
    int pivotElement = arr[s];

    //2. Find Right position for pivot element and place it there
    int count =0;
    for(int i=s+1; i<=e; i++)
    {
        if(arr[i] <= pivotElement)
            count++;
        
    }
    //after coming out of loop we got right position for pivot

    int rightIndex = s + count;
    swap(arr[pivotIndex], arr[rightIndex]);
    pivotIndex = rightIndex;

    //3. left me chote and right me bade element
    int i=s;
    int j= e;
    while(i <= pivotElement && j > pivotIndex) //!
    {
        while(arr[i] <= pivotElement)
        {
            i++;
        }
        while(arr[j] > pivotElement)
        {
            j--;
        }

        //* 2 case hoskte hai 
        // A -> You found the elements to swap  
        // B-> No need to swap 
        if(i <= pivotElement && j > pivotIndex) //!
            swap(arr[i], arr[j]);
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e)
{
    if(s>= e)
        return;
    //partition logic, return pivotIndex

    int p =partition(arr,s,e);

    //recursive calls
    //left
    quickSort(arr,s,p-1);
    //right
    quickSort(arr,p+1,e);
    
}

int main()
{
    // int arr[] = {8,1,20,30,6,5,60,5};
    int arr[] = {45, 73, 12, 89, 67, 23, 56, 90, 34, 18, 97, 51, 72, 29, 81, 64, 10, 40, 55, 78, 33, 66, 22, 87, 39, 16, 94, 62, 31, 85, 70, 48, 11, 76, 20, 54, 36, 68, 28, 79, 44, 15, 92, 60, 25, 88, 47, 71, 38, 17, 93, 63, 32, 86, 30, 75, 50, 21, 35, 65, 27, 77, 42, 13, 91, 58, 24, 69, 37, 80, 43, 14, 95, 61, 26, 74, 49, 19, 96, 52, 1, 98, 57, 41, 82, 46, 2, 99, 53, 3, 83, 59, 4, 84, 5, 6, 7, 8, 9};

    int n =sizeof(arr)/ sizeof(int);
    cout << n<< endl;
    int s =0;
    int e = n-1;
    quickSort(arr,s,e);

    for(int i=0; i<n; i++)
    {
        cout<< arr[i]<< " ";
    }
    cout << endl;
    return 0;
}