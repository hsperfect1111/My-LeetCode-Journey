// 41.
// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
// 448. Find All Numbers Disappeared in an Array
// YT : https://www.youtube.com/watch?v=oEBHLcucDYg

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;

        // Mark indices corresponding to the numbers seen in the array
        for(int i=0; i<n; i++)
        {
            int idx = abs(nums[i]) - 1;
            // Mark the number at that index as negative to indicate presence
            if(nums[idx] < 0)
                continue;
            
            nums[idx] *= -1;
        }

        // Collect indices where values are still positive
        // These indices + 1 are the missing numbers
        for(int i=0; i<n; i++)
        {
            if(nums[i] > 0)
            {
                res.push_back(i+1);
            }
        }

        return res;
    }
};
