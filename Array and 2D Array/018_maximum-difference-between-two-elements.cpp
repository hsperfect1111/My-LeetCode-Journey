// 18.
// https://www.geeksforgeeks.org/maximum-difference-between-two-elements/
// Maximum Difference between Two Elements such that Larger Element Appears after the Smaller Element

// => [Naive Approach] Using Two Nested Loops – O(n^2) time and O(1) space 

#include<bits/stdc++.h>
using namespace std;

int maxDiff(vector<int> &arr)
{
    int n = arr.size();
    int ans = -1;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[j] > arr[i])
            {
                ans = max(ans, arr[j]-arr[i]);
            }
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {2,3,10,6,4,8,1};
    cout << maxDiff(arr);
    return 0;
}

// => [Efficient Approach – 1] Using Single Traversal – O(n) time and O(1) space

#include<bits/stdc++.h>
using namespace std;

int maxDiff(vector<int> &arr)
{
    int n = arr.size();
    int ans = -1;
    int mini = arr[0];
    
    for(int i=0; i<n; i++)
    {
        if(arr[i]<=mini)
        {
            mini = arr[i];
        }
        else
        {
            ans = max(ans, arr[i] - mini);
        }
    }
    return ans ;
}

int main()
{
    vector<int> arr = {2,3,10,6,4,8,1};
    cout << maxDiff(arr);
    return 0;
}


// => [Efficient Approach – 2] Using Kadane’s Algorithm – O(n) time and O(1) space

#include<bits/c++.h>
using namespace std;

int maxDiff(vector<int> &arr)
{
    int n = arr.size();
    int diff = arr[1] - arr[0];
    int currSum = diff;
    int maxSum = -1;
    
    for(int i=1; i<n-1; i++)
    {
        diff = arr[i+1] - arr[i];
        
        // Yeh arr[i+1] - arr[i] ka difference le raha hai — aur iss difference ko currSum
        // mein jod raha hai agar previous sum positive tha, warna naye se start kar raha hai.
        if(currSum > 0)
        {
            currSum += diff;
        }
        else
        {
            currSum = diff;
        }
        // Update max sum
        if(currSum > 0 && currSum > maxSum)
        {
            maxSum = currSum;
        }
    }
    return maxSum;
}

int main()
{
    vector<int> arr = {2,3,10,6,4,8,1};
    cout << maxDiff(arr);
    return 0;
}

// Example Dry Run:
// Given: {2, 3, 10, 6, 4, 8, 1}

// Difference array:

// 3 - 2 = 1

// 10 - 3 = 7

// 6 - 10 = -4

// 4 - 6 = -2

// 8 - 4 = 4

// 1 - 8 = -7

// So difference array: 1, 7, -4, -2, 4, -7

// Ab uss pe Kadane's lagao:

// curr = 1 → max = 1

// curr += 7 → 8 → max = 8

// curr += -4 → 4

// curr += -2 → 2

// curr += 4 → 6

// curr += -7 → -1

// Max = 8, which is between 2 (index 0) and 10 (index 2)
