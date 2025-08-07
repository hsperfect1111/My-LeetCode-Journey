// 12.
// 46. Permutations
// https://leetcode.com/problems/permutations/  (Must try)
// METHOD : 1  and below down //METHOD : 2 is easy and understood

class Solution {
public:
    vector<vector<int>> ans;  // To store all the permutations

    // Helper function to generate permutations
    void permuteHelper(vector<int>& nums, int i) {
        // Base case: If i reaches the size of nums, we have a complete permutation
        if (i == nums.size()) {
            ans.push_back(nums);  // Add the current permutation to the answer list
            return;
        }

        // Loop through the remaining elements starting from index i
        for (int j = i; j < nums.size(); j++) {
            // Swap the current element with the element at position i
            swap(nums[i], nums[j]);

            // Recursively generate permutations for the subarray starting from i + 1
            permuteHelper(nums, i + 1);

            // Undo the swap (backtrack) to restore the array to its previous state
            swap(nums[i], nums[j]);
        }
    }

    // Main function to generate permutations of the input array
    vector<vector<int>> permute(vector<int>& nums) {
        permuteHelper(nums, 0);  // Start the recursive process from the first element
        return ans;  // Return the result containing all permutations
    }
};



// 1 2 3 4
// return all the possible permutations = 4*3*2*1 = 4! = 24

// 1 2 3 4 5
// return all the possible permutations = 5*4*3*2*1 = 5! = 120
