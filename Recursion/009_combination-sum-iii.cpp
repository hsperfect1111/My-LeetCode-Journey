// 9.
// 216. Combination Sum III
// https://leetcode.com/problems/combination-sum-iii/description/ 
// https://www.youtube.com/watch?v=77KQifr--ek

class Solution {
public:
    void helper(int idx, int sum, int n, vector<vector<int>>& ans, vector<int>& current, int k)
    {
        // base case
        if(sum == n && k == 0)
        {
            ans.push_back(current);
            return;
        }

        if(sum>n || k == 0)
            return;

        for(int i=idx; i<=9; i++)
        {
            current.push_back(i);
            helper(i+1, sum+i, n, ans, current, k-1);
            current.pop_back();
        }

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> ans;
        vector<int> current;
        helper(1, 0, n, ans, current, k);
        return ans;
    }
};
