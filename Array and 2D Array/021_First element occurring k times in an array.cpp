// 21.
// First element occurring k times in an array
// https://www.geeksforgeeks.org/first-element-occurring-k-times-array/

// [Naive Approach] Using Two Nested Loops – O(n2) time and O(1) auxiliary space:

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
            
            if(count == k)
            {
                return arr[i];
            }
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1,7,4,3,4,8,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    cout << firstElement(arr, n, k);
    return 0;
}

// Time complexity: O(n2).
// Auxiliary space: O(1) as it is using constant space for variables

// 			-------------

// [Expected Approach] Using Hashing – O(n) time and O(n) auxiliary space:

#include <bits/stdc++.h>
using namespace std;

int firstElement(int arr[], int n, int k)
{
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++)
    {
        mp[arr[i]]++;
    }
    
    for(int i=0; i<n; i++)
    {
        if(mp[arr[i]] == k)
        {
            return arr[i];
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1,7,4,3,4,8,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    cout << firstElement(arr, n, k);
    return 0;
}

// Time Complexity: O(n)
// Auxiliary Space: O(n) because we are using an auxiliary array of size n to store the count
 