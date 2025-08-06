// 8.
// 40. Combination Sum II
// https://leetcode.com/problems/combination-sum-ii/description/
// YT : https://www.youtube.com/watch?v=bfKwLi6jtDk

class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<int>& curr, int idx, vector<vector<int>>& result)
    {
        // {100, 2} , target = 1
        // target - 100 = 1 - 100 = -90
        if(target < 0)
            return;

        if(target == 0)
        {
            result.push_back(curr);
            return;
        }

        for(int i=idx; i<candidates.size(); i++)
        {
            if(i>idx && candidates[i] == candidates[i-1])
            {
                continue;
            }

            curr.push_back(candidates[i]); // Do
            solve(candidates, target-candidates[i], curr, i+1, result); // EXPLORE
            curr.pop_back(); // UNDO
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       vector<vector<int>> result;
       vector<int> curr;
       sort(candidates.begin(), candidates.end());
       solve(candidates, target, curr, 0, result);

       return result;
    }
};


// Let n be the number of elements in candidates.
// Let k be the average length of a combination in the result.
// Now, in the worst case, the backtracking explores every subset (like the power set), which is 2^n.

// TC ≈ O(2^n * k)
// 2^n = all possible subsets.
// k = time to copy current list (curr) into result.

// Space Complexity (SC):
// Auxiliary space: O(k) for the recursion stack (curr path length).

// Result space: If there are m valid combinations, and each combination has length up to k:
// Sc = k * x
// Sc = O(k) + O(m * k) = O(m * k)
