// 30.
// https://leetcode.com/problems/next-permutation/description/
// 31. Next Permutation
// YT : https://www.youtube.com/watch?v=JDOXKqF60RQ

// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         // In order to generate all the possible permutations use recursion
//         next_permutation(nums.begin(), nums.end());
//         // You're using next_permutation() from the STL — which is totally fine ✅ if you're allowed to use it.
//         // return nums; // can't return a value from a void function.
//     }
// };

                // most optimal solution
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        // can use implement inbuilt STL 
        int n = nums.size();
        int ind = -1;

        // Step 1: Find the first decreasing element from the end
        for(int i=n-2; i>=0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                ind = i;
                break;
            }
        }
        
        // Step 2: If no such index found, reverse entire array
        if(ind == -1)
        {
            reverse(nums.begin(), nums.end());
            return ;
        }    

        for(int i=n-1; i>ind; i--)
        {
            if(nums[i]>nums[ind])
            {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        // Step 4: Reverse the elements after ind
        reverse(nums.begin() + ind + 1, nums.end());  
    }
};

// TC = O(3N) worst case
// SC = O(N) for modifying the array otherwise O(1) not using extra space
