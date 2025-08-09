// 17.
// 377. Combination Sum IV
// https://leetcode.com/problems/combination-sum-iv/description/
// YT : https://www.youtube.com/watch?v=YyuwTwXzSxY

// Why Backtracking ?
// All possible/ permutations / combinations / subsets etc.

// NOTE : Ye accept nhi hoga kyuki ye exponential solution h constraint bada h is baar
// class Solution {
// public:
//     int n;
    
//     int solve(int idx, vector<int>& nums, int target)
//     {
//         if(target == 0)
//             return 1;

//         // idx bhej rahe ho to out of bound check kr lena 
//         if(idx >= n || target < 0)
//             return 0;

//         int take_idx = solve(0, nums, target-nums[idx]);
//         int reject_idx = solve(idx+1, nums, target);

//         return take_idx + reject_idx;
//     }

//     int combinationSum4(vector<int>& nums, int target) {
//         n = nums.size();
//         return solve(0, nums, target);
//     }
// };


// har element ko do moke de rahe ho ek baar usko le rahe ho aur nhi bhi le rahe ho to iska exponential time complexity h toh definately isko memorize krna padega 
// memorize karane k liye do cheez change ho rahi h ek idx change ho raha h aur target change ho raha h toh meri dp jo hoga woh 2D-Array ka hoga t[][]

// class Solution {
// public:
//     int n;
//     int t[201][1001];
//     int solve(int idx, vector<int>& nums, int target)
//     {
//         if(target == 0)
//             return 1;

//         // idx bhej rahe ho to out of bound check kr lena 
//         if(idx >= n || target < 0)
//             return 0;

//         if(t[idx][target] != -1)
//             return t[idx][target];

//         int take_idx = solve(0, nums, target-nums[idx]);
//         int reject_idx = solve(idx+1, nums, target);

//         return t[idx][target] = take_idx + reject_idx;
//     }

//     int combinationSum4(vector<int>& nums, int target) {
//         n = nums.size();
//         memset(t, -1, sizeof(t));
//         return solve(0, nums, target);
//     }
// };

// same template using for loop:
// for loop reject ka kaam kr deta h humare liye  
class Solution {
public:
    int n;
    int t[201][1001];
    int solve(int idx, vector<int>& nums, int target)
    {
        if(target == 0)
            return 1;

        // idx bhej rahe ho to out of bound check kr lena 
        if(idx >= n || target < 0)
            return 0;

        if(t[idx][target] != -1)
            return t[idx][target];

        int result = 0;
        for(int i=0; i<n; i++)
        {
            int take_i = solve(0, nums, target-nums[i]);
            result += take_i;
        }

        return t[idx][target] = result;
    }

    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(0, nums, target);
    }
};
