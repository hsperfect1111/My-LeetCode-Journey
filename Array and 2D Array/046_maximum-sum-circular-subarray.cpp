// 46.
// https://leetcode.com/problems/maximum-sum-circular-subarray/submissions/1624670515/
// 918. Maximum Sum Circular Subarray
// Yt : https://www.youtube.com/watch?v=Za8V4wkZKkM

// NOTE: TLE - Time Limit Exceeded
// Kadane's Algorithm is primarily used to find the maximum sum of a contiguous subarray within a one-dimensional array of numbers (which can include both positive and negative numbers). It's one of the most efficient algorithms for solving this problem, running in linear time, O(n).

// Approach Brute Force:
// class Solution {
// public:
//     // Kadane's Algorithm to find max subarray sum
//     int kadane(vector<int>& nums)
//     {
//         int sum = nums[0];
//         int maxSum = nums[0];

//         for(int i = 1; i < nums.size(); i++)
//         {
//             // This stores the sum of the current subarray.
//             // At each index it decides:
//                 // Should I start a new subarray from the current element?
//                 // Or should I continue by adding it to the current sum?
//             sum = max(sum + nums[i], nums[i]);

//             // This keeps track of the largest subarray sum so far.
//             // At each step it checks:
//                 // Is maxEndingHere the best so far?
//             maxSum = max(maxSum, sum);
//         }
//         return maxSum;
//     }

//     // Left rotate the array by 1 position
//     void rotate(vector<int>& nums)
//     {
//         int first = nums[0];
//         for(int i = 0; i < nums.size() - 1; i++)
//         {
//             nums[i] = nums[i + 1];
//         }
//         nums[nums.size() - 1] = first;
//     }

//     int maxSubarraySumCircular(vector<int>& nums) {
//         int n = nums.size();
//         int result = INT_MIN;

//         for(int i = 0; i < n; i++)
//         {
//             int currentSum = kadane(nums);  // Max subarray sum for current rotation
//             result = max(result, currentSum);   // Track maximum
//             rotate(nums);   // Rotate array to the left by 1
//         }
//         return result;
//     }
// };

// Time Complexity:
// Rotation = O(n) per loop
// Kadane's = O(n) per loop
// Loop runs n times ⇒ Total = O(n^2) 

// Optimal (Kadane's)
// class Solution {
// public:

//     // Kadane's Algorithm to find max subarray sum
//     int kadanesMax(vector<int>& nums, int n)
//     {
//         int sum = nums[0];
//         int maxSum = nums[0];

//         for(int i = 1; i < nums.size(); i++)
//         {
//             // This stores the sum of the current subarray.
//             // At each index it decides:
//                 // Should I start a new subarray from the current element?
//                 // Or should I continue by adding it to the current sum?
//             sum = max(sum + nums[i], nums[i]);

//             // This keeps track of the largest subarray sum so far.
//             // At each step it checks:
//                 // Is maxEndingHere the best so far?
//             maxSum = max(maxSum, sum);
//         }
//         return maxSum;
//     }

//     int kadanesMin(vector<int>& nums, int n)
//     {
//         int sum = nums[0];
//         int minSum = nums[0];

//         for(int i = 1; i < nums.size(); i++)
//         {
//             // This stores the sum of the current subarray.
//             // At each index it decides:
//                 // Should I start a new subarray from the current element?
//                 // Or should I continue by adding it to the current sum?
//             sum = min(sum + nums[i], nums[i]);

//             // This keeps track of the smallest subarray sum so far.
//             // At each step it checks:
//                 // Is minEndingHere the smallest so far?
//             minSum = min(minSum, sum);
//         }
//         return minSum;
//     }

//     int maxSubarraySumCircular(vector<int>& nums)
//     {
//         int n = nums.size();

//         // 1. First, calculate the total sum — can also be done with a for-loop
//         int SUM = accumulate(begin(nums), end(nums), 0);

//         // 2. Find the minimum subarray sum using kadanesMin algorithm
//         int minSum = kadanesMin(nums, n);

//         // 3. The maximum sum can come from the normal (non-circular) array or from the circular one
//         int maxSum = kadanesMax(nums, n);   // Case 1: non-circular

//         // 4. For circular case: circular sum = Total Sum - Minimum Subarray Sum
//         int circular_sum = SUM - minSum;

//         // 5. If all elements are not negative, return the maximum of both cases
//         if(maxSum > 0)
//         {
//             return max(maxSum, circular_sum);
//         }

//         // 6. Otherwise, return maxSum (in case all elements are negative)
//         return maxSum;
//     }
// };


// How to calculate min sum subArray
// int kadane(vector<int>& nums)
// {
//     int sum = nums[0];
//     int minSum = nums[0];

//     for(int i = 1; i < n; i++)
//     {
//         sum = min(sum + nums[i], nums[i]);
//         minSum = min(minSum, sum);
//     }
//     return minSum;
// }
