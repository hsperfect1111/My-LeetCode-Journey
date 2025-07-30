// 39.
// https://leetcode.com/problems/first-missing-positive/description/
// 41. First Missing Positive
// YT : https://www.youtube.com/watch?v=LLdHZI-qC08

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Replace non-positive numbers with n+1
        for(int i=0; i<n; i++)
        {
            if(nums[i] <= 0)
            {
                nums[i] = n+1;
            }
        }

        // Step 2: Use index marking
        for(int i=0; i<n; i++)
        {
            int index = abs(nums[i]) - 1;
            if(index < n)
            {
                nums[index] *= -1;
            }
            
        }

        // Step 3: First index with positive value => missing number
        for(int i=0; i<n; i++)
        {
            if(nums[i] > 0)
            {
                return i+1;
            }
        }
        return n+1;
    }
};


// USing chatGPT : For better understanding
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Replace non-positive numbers with n+1
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0) {
                nums[i] = n + 1;
            }
        }

        // Step 2: Use index marking
        for (int i = 0; i < n; i++) {
            int val = abs(nums[i]);
            if (val >= 1 && val <= n) {
                if (nums[val - 1] > 0) {
                    nums[val - 1] *= -1;
                }
            }
        }

        // Step 3: First index with positive value => missing number
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        return n + 1;
    }
};
