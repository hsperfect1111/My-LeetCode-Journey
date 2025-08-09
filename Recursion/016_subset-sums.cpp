// 16.
// Subset Sums
// https://www.geeksforgeeks.org/problems/subset-sums2234/1

class Solution {
  public:
    void func(int idx, int sum, vector<int>& arr, int N, vector<int> &sumSubset)
    {
        if(idx == N)
        {
            sumSubset.push_back(sum);
            return;
        }
        
        // pick the element
        func(idx+1, sum + arr[idx], arr, N, sumSubset);
        
        // Do-not pick the element
        func(idx+1, sum, arr, N, sumSubset);
    }

    vector<int> subsetSums(vector<int>& arr) {
        // code here
        int N = arr.size();
        vector<int> sumSubset;
        func(0, 0, arr, N, sumSubset);
        sort(sumSubset.begin(), sumSubset.end());
        return sumSubset;
    }
};

// If n = 3, the number of subsets = 2^n = 8

// First Approach: Brute Force
// You have to generate all the subsets using the Power Set approach.
// Reference video: https://www.youtube.com/watch?v=LqKaUv1G3_I

// Power Set takes O(2^n * n) time to generate all subsets,
// where `n` is the number of elements, and each subset can have up to `n` elements.
// This approach commonly uses bit manipulation to generate subsets.

// Time Complexity:
// For every index, there are 2 choices — either pick it or not.
// So, for `n` elements, the total number of combinations = 2^n
// Therefore, Time Complexity = O(2^n)

// If we sort all subset sums afterward,
// Time and Space Complexity = O(2^n * log(2^n))
// The log(2^n) comes from the sorting step
