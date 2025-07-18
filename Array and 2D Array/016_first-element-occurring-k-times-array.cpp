16.
https://www.geeksforgeeks.org/first-element-occurring-k-times-array/
First element occurring k times in an array

#include <bits/stdc++.h>
using namespace std;

int firstElement(int arr[], int n, int k)
{
    for(int i=0; i<n; i++)
    {
        int count = 0;
        for(int j=0; j<n; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
            }
        }
        
        if(count == k)
        {
            return arr[i];
        }
    }
    return -1;
}


int main()
{
    int arr[] = {1, 7, 4, 3, 4, 8, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    cout << firstElement(arr, n, k);
    return 0;
}
