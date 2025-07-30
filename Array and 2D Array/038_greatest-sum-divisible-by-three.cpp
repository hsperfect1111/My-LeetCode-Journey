// 38.
// NOTE : ✅ Tag this question as DP in your sheet.
// https://leetcode.com/problems/greatest-sum-divisible-by-three/description/
// 1262. Greatest Sum Divisible by Three
// YT : https://www.youtube.com/watch?v=u_2kOwmJQW4

// By understanding chatGPT and video
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, 0);   // This line creates a vector of size 3, and initializes all values to 0. dp = [0, 0, 0];   // dp[0] = max sum % 3 == 0, dp[1] = max sum % 3 == 1, dp[2] = max sum % 3 == 2
        for(int i=0; i < nums.size(); i++)
        {
            vector<int> curr = dp;  // Ye line dp ka ek copy bana rahi hai jiska naam curr hai. curr[0], curr[1], curr[2] = current state ke old values. Jab hum dp ko update karenge, curr unchanged rahega.
// dp ka ek copy banao taaki update safe ho
            for(int j=0; j<3; j++)
            {
                int mod = (curr[j] + nums[i])%3;
                dp[mod] = max(dp[mod], curr[j] + nums[i]);
            }
        }
        return dp[0];   // maximum sum divisible by 3
    }
};
