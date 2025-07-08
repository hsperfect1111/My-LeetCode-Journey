// Interview specific Question sheet
// Array and 2D Array - 
// Q1.

// Kadane's Algorithm
// https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
// YT : https://www.youtube.com/watch?v=CDjwkAkk9-U

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        int currSum = 0;
        int maxi = INT_MIN;
        
        for(int i=0; i<n; i++)
        {
            currSum += arr[i];
            maxi = max(maxi, currSum);
            
            if(currSum < 0)
            {
                currSum = 0;
            }
        }
        return maxi;
    }
};