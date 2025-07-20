// 20.
// 152. Maximum Product Subarray
// https://leetcode.com/problems/maximum-product-subarray/description/
// YT : https://www.youtube.com/watch?v=hnswaLJvr6g

// Brute-Force 
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int maxi = INT_MIN;
//         int n = nums.size();
//         // Outer loop (i):
//         // Marks the start index of the subarray.
//         for(int i=0; i<n; i++)
//         {
//             // Middle loop (j):
//             // Marks the end index of the subarray.
//             for(int j=i; j<n; j++)
//             {
//                 int prod = 1;
//                 // Inner loop (k):
//                 // Iterates from i to j (inclusive) to multiply all elements in that subarray → nums[i...j].
//                 for(int k=i; k<=j; k++)
//                 {
//                     prod = prod * nums[k];
//                 }
//                 maxi = max(maxi, prod);
//             }
//         }
//         return maxi;
//     }
// };

// Time Complexity:
// O(n³) — very slow for large input.
// Outer loop: O(n)
// Middle loop: O(n)
// Inner loop (product calculation): O(n)

// Optimized Version — O(n) Time Complexity
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();
//         int maxi = INT_MIN;
//         for(int i=0; i<n; i++)
//         {
//             int prod=1;
//             for(int j=i; j<n; j++)
//             {
//                 prod = prod * nums[j];
//                 maxi = max(maxi, prod);
//             }
//         }
//         return maxi;
//     }
// };

// Time Complexity:
// O(n²) — Much better than O(n³), but still not optimal.
// Space Complexity: O(1) — No extra space used.

// Best : watch video for this

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre = 1, suff = 1;
        int ans = INT_MIN; 
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            if(pre == 0) pre = 1;
            if(suff == 0) suff = 1;
            
            pre = pre * nums[i];
            suff = suff * nums[n-1-i];
            ans = max(ans, max(pre, suff));
            
        }
        return ans;
    }
};

// TC = O(N)
// SC = O(1)
