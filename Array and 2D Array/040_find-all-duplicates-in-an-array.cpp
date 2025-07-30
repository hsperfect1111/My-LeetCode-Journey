// 40.
// https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
// 442. Find All Duplicates in an Array
// YT : https://www.youtube.com/watch?v=ACYunkWQnSI

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i=0; i<n; i++)
        {
            int index = abs(nums[i]) - 1;
            if(nums[index] < 0)
            {
                res.push_back(abs(nums[i]));
            }
            nums[index] *= -1;
        }
        return res;
    }
};
