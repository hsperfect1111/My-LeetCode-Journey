// Leetcode Problem 78: Subsets
// METHOD 1 USING RECURSION:
// The following code generates all subsets of a given array (nums).
// If there are 'n' elements, it will generate 2^n subsets.


// RECURSIVE APPROACH 1 (RETURNING VALUE)
/*
class Solution {
public:`
    // Helper function to generate subsets recursively
    vector<vector<int>> subsetsHelper(vector<int>& nums, int i) {
        
        // Base case: if 'i' equals the size of nums, return a set containing only an empty subset
        // (This is the last subset before we start adding elements)
        if(i == nums.size()) return {{}};

        // Recursive step: generate subsets for the remaining elements starting from index i+1
        vector<vector<int>> partial_ans = subsetsHelper(nums, i+1); 
        // Q: Why are we starting from i+1?
        // A: So we get the subsets that exclude the first element. 
        // One copy will be made without adding the first element,
        // and the second copy will be made with the first element added.

        // Make a copy of the generated subsets so we can add the current element to them
        vector<vector<int>> dup_partial_ans = partial_ans;

        // Add the current element (nums[i]) to each of the subsets in the duplicate list
        for(auto &v : dup_partial_ans) {
            v.push_back(nums[i]);  // Insert current element nums[i] into each subset
        }

        // Create a vector to store the final result
        vector<vector<int>> ans;

        // Merge both lists of subsets (the ones without current element and with current element)
        // First, add all subsets that don't include nums[i]
        for(auto a : partial_ans) ans.push_back(a);

        // Then, add all subsets that include nums[i]
        for(auto a : dup_partial_ans) ans.push_back(a);

        // Return the combined list of subsets
        return ans;
    }

    // Function to generate all subsets of the input vector 'nums'
    vector<vector<int>> subsets(vector<int>& nums) {
        // Call the helper function starting from index 0 to generate subsets
        vector<vector<int>> ans = subsetsHelper(nums, 0);
        return ans;
    }
};
*/


// RECURSIVE APPROACH 2 (VOID FUNCTION USING GLOBAL ANSWER)
/*
class Solution {
public:
    // Declared a global variable to store the final answer
    vector<vector<int>> ans;

    // Helper function to generate subsets recursively
    // Here we perform our own task first before recursion
    void subsetsHelper(vector<int>& nums, int i, vector<int>& subset) {
        // Base case: if 'i' equals the size of nums, save the formed subset into the final answer
        if(i == nums.size()) {
            ans.push_back(subset);
            return;
        }

        // CASE 1: Include the current element (nums[i]) in the subset and call recursion
        subset.push_back(nums[i]);
        subsetsHelper(nums, i+1, subset);

        // CASE 2: Exclude the current element and call recursion again
        subset.pop_back();
        subsetsHelper(nums, i+1, subset);
    }

    // Function to generate all subsets of the input vector 'nums'
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset; // Created a temporary subset vector and passed to helper
        subsetsHelper(nums, 0, subset);
        return ans;
    }
};
*/


// METHOD 2 : Iterative Approach using Bit Manipulation

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();

        int end = (1 << n) - 1;  // Calculate 2^n using bit shift: (1 << n)
                                // Example: (1 << 3) = 2^3 = 8 --> binary 1000

        vector<vector<int>> answer = {};

        // Iterate from 0 to 2^n - 1 to generate all combinations
        for(int i = 0; i <= end; i++) {
            vector<int> row = {};

            // Now we check which bits are set in the current number 'i'
            for(int j = 0; j < 31; j++) {  
                // Using 31 here is fine because we are not dealing with negative numbers
                if(i & (1 << j)) {  // If j-th bit is set in 'i', include nums[j] in the subset
                    row.push_back(nums[j]);
                }
            }

            answer.push_back(row); // Add the current subset to the final answer
        }

        return answer;
    }
};
