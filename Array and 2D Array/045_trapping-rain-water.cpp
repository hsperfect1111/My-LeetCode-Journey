// 45.
// https://leetcode.com/problems/trapping-rain-water/description/
// 42. Trapping Rain Water
// YT : // Apna college : https://www.youtube.com/watch?v=UHHp8USwx4M
// YT : https://www.youtube.com/watch?v=1_5VuquLbXg

// Striver playlist Line : 29 IMP
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         if (n == 0) return 0;

//         vector<int> prefix(n), suffix(n);
        
//         // Build prefix max array (left max)
//         prefix[0] = height[0];
//         for (int i = 1; i < n; i++) {
//             prefix[i] = max(prefix[i - 1], height[i]);
//         }

//         // Build suffix max array (right max)
//         suffix[n - 1] = height[n - 1];
//         for (int i = n - 2; i >= 0; i--) {
//             suffix[i] = max(suffix[i + 1], height[i]);
//         }

//         // Calculate trapped water
//         int total = 0;
//         for (int i = 0; i < n; i++) {
//             int leftMax = prefix[i];
//             int rightMax = suffix[i];

//             if (height[i] < leftMax && height[i] < rightMax) {
//                 total += min(leftMax, rightMax) - height[i];
//             }
//         }

//         return total;
//     }
// };

// video : 4:30
// At any position i, to trap water:
// There must be a wall to the left that's higher → prefix[i]
// There must be a wall to the right that's higher → suffix[i]

// ek bulding k upar kitna unit water store ho raha h uska formula:
// min(leftMax, RightMax) - arr[i];
// keypoint 
// leftMax, RightMax should be greater than arr[i] so, that it can hold the water only


// TC = O(2N) + O(N)
//    = O(3N) = O(N)
// Sc = O(2N) = O(N)


// Apna college : https://www.youtube.com/watch?v=UHHp8USwx4M
// Optimal approach

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int l = 0 , r = n-1;
        int lmax = 0 , rmax = 0;
        
        while(l < r)
        {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);

            if(lmax < rmax)
            {
                ans += lmax - height[l];
                l++;
            }
            else
            {
                ans+= rmax - height[r];
                r--;
            }
        }
        return ans;
    }
};
