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

// Doubt Session - 10
// 12-Nov-2024 (Tue)

// METHOD : 2 is easy and understood

// Watch the video for better understanding 

class Solution {
public:
    // We create a final answer vector to store all the combinations to be returned
    vector<vector<int>> answer = {};

    // R(0) ->  0 -- 0,   0 -- 1 ,    0 -- 2
              // index  i    index  i+1    index  i+2

    void recursion(int index, vector<int>& nums)
    {
        // Base case ~ STOP condition
        if(index == nums.size())
        {
            answer.push_back(nums);
            return;
        }

        // Recursive case ~ options
        for(int i = index; i < nums.size(); i++)
        {
            // Choose the i-th option - swap -> nums[i], nums[index]
            swap(nums[i], nums[index]);

            recursion(index + 1, nums);

            // Undo the state (backtrack)
            swap(nums[i], nums[index]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        recursion(0, nums);

        return answer;
    }
};

// In recursion, if there are 'n' options, we use a for-loop inside recursion
// And its Time Complexity = n^n
