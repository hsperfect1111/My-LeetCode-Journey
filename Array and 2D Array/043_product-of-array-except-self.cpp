// 43.
// https://leetcode.com/problems/product-of-array-except-self/description/
// 238. Product of Array Except Self
// YT : https://www.youtube.com/watch?v=G9zKmhybKBM

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        vector<int> ans(n);

        // Fill left product array
        left[0] = 1;
        for(int i=1; i<n; i++)
        {
            left[i] = left[i-1] * nums[i-1];
        }

        // Fill right product array
        right[n-1] = 1;
        for(int i=n-2; i>-1; i--)
        {
            right[i] = right[i+1] * nums[i+1];
        }

        // Multiply left and right for the result
        for(int i=0; i<n; i++)
        {
            ans[i] = left[i] * right[i];
        }

        return ans;

    }

};
