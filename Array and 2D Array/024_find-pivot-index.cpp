// 24.
// https://leetcode.com/problems/find-pivot-index/description/
// 724. Find Pivot Index
// YT : https://www.youtube.com/watch?v=2x5QL3Z_p8Y

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int rightSum = 0;
        for(int i=0; i<n; i++)
        {
            rightSum += nums[i];
        }

        int leftSum = 0;
        for(int i=0; i<n; i++)
        {
            rightSum -= nums[i];
            if(leftSum == rightSum)
            {
                return i;
            }

            leftSum += nums[i];
        }

    return -1;
    }
    
};

// Time Complexity (TC):
// O(n)

// First loop (calculating rightSum) runs once over all n elements → O(n)

// Second loop (checking pivot index) also runs once over n elements → O(n)

// Total = O(n) + O(n) = O(n)

// Space Complexity (SC):
// O(1)

// You're only using a few integer variables: rightSum, leftSum, and i

// No extra space that grows with input size

// So overall = constant space, i.e., O(1)
