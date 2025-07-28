// 29.
// https://leetcode.com/problems/rearrange-array-elements-by-sign/description/
// 2149. Rearrange Array Elements by Sign

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int posIndex = 0, negIndex = 1;
        for(int i=0; i<n; i++)
        {
            if(nums[i] < 0)
            {
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
            else
            {
                ans[posIndex] = nums[i];
                posIndex += 2;
            }
        }
        return ans;
    }
};

// arr[] = [3, 1, -2, -5, 2, 4]
// 		   0 2 4
// pos =  [3 1 2]		N/2
// 		0 1 2

// neg = [-2 -5 -4]
// 		   1  3  5

// for( i=0; i<N/2; i++)
// {
// 	arr[2*i] = pos[i]
// 	arr[2*i+1] = neg[i]
// }

// Tc = O(N) + O(N)
// Sc = O(N)
