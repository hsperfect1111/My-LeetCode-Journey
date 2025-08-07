// Leetcode 1863: Sum of All Subset XOR Totals
// YouTube Reference: https://www.youtube.com/watch?v=3tzP38WPAoA

// NOTE: Watch this video to understand how to generate subsets:
// https://www.youtube.com/watch?v=p4bP_FIXGWw


// -----------------------------
// Approach 1: Generate all subsets, calculate XOR
// -----------------------------

class Solution {
public:
    // Helper function to generate all subsets recursively
    void solve(vector<int>& nums, int i, vector<int>& currSubset, vector<vector<int>>& subsets)
    {
        // Base case: if index reaches end, save the current subset
        if(i == nums.size())
        {
            subsets.push_back(currSubset);
            return;
        }

        // Include current element and recurse
        currSubset.push_back(nums[i]);
        solve(nums, i+1, currSubset, subsets);

        // Backtrack (remove current element) and recurse
        currSubset.pop_back();
        solve(nums, i+1, currSubset, subsets);
    }

    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> currSubset;

        // Step 1: Generate all subsets
        solve(nums, 0, currSubset, subsets);

        // Step 2: Calculate XOR of each subset and add to result
        int result = 0;
        for(vector<int>& subset : subsets)
        {
            int Xor = 0;

            // Calculate XOR of all elements in the current subset
            for(int &num : subset)
            {
                Xor ^= num;
            }

            // Add current subset's XOR to the total result
            result += Xor;
        }

        return result;
    }
};

/*
Time Complexity: O(2^n * l)
→ 2^n subsets generated, each having up to l elements.

Space Complexity: O(2^n * l)
→ Storing all subsets explicitly.

Example:
For nums = [1, 2]:

Subsets: [], [1], [2], [1, 2]

XORs:
[]     → 0
[1]    → 1
[2]    → 2
[1,2]  → 1^2 = 3

Result = 0 + 1 + 2 + 3 = 6

Explanation:
for(vector<int>& subset : subsets)
→ Iterates over each subset

for(int &num : subset)
→ Calculates XOR of all elements in that subset
*/


// -----------------------------
// Approach 2: Recursive, No subset storage (optimized)
// -----------------------------

/*
class Solution {
public:
    // Recursive function to calculate XOR total directly
    int solve(vector<int>& nums, int i, int Xor)
    {
        if(i == nums.size())
        {
            return Xor; // Reached the end, return current XOR
        }

        // Option 1: Include current element in XOR
        int include = solve(nums, i+1, nums[i]^Xor);

        // Option 2: Exclude current element
        int exclude = solve(nums, i+1, Xor);

        return include + exclude;
    }

    int subsetXORSum(vector<int>& nums) {
        return solve(nums, 0, 0);
    }
};
*/

/*
Time Complexity: O(2^n)
→ Each element has 2 choices → include or exclude

Space Complexity: O(n)
→ Depth of recursion stack is n (1 call per element)
→ No extra space used to store subsets
*/


// -----------------------------
// Approach 3: Bitwise Trick (Optimized)
// -----------------------------

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();

        int result = 0;

        // Take OR of all elements
        for(int &num : nums)
        {
            result |= num;
        }

        // Left shift by (n-1) positions (i.e., multiply by 2^(n-1))
        return result << (n-1);
    }
};

/*
Explanation:
→ XOR distributes over OR for subsets
→ For all subsets, total XOR sum = OR of all elements * 2^(n-1)

Time Complexity: O(n)
→ One pass over the array

Space Complexity: O(1)
→ No extra space used
*/
