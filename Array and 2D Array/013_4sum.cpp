13.
https://leetcode.com/problems/4sum/description/
18. 4Sum
YT : https://www.youtube.com/watch?v=eD95WRfh81c

// NOTE : Time Limit Exceeded
// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         set<vector<int>> st;
//         for(int i=0; i<n; i++)
//         {
//             for(int j=i+1; j<n; j++)
//             {
//                 for(int k=j+1; k<n; k++)
//                 {
//                     for(int l=k+1; l<n; l++)
//                     {
//                         long long sum = nums[i] + nums[j];
//                         sum += nums[k];
//                         sum += nums[l];
//                         if(sum == target)
//                         {
//                             vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
//                             sort(temp.begin(), temp.end());
//                             st.insert(temp);
//                         }
//                     }
//                 }
//             }
//         }
//         vector<vector<int>> ans(st.begin(), st.end());
//         return ans;
//     }
// };

// TC = O(n^4)
// Sc = O(no.of quadruplets ) * 2

// Optimal solution
// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         set<vector<int>> st;
//         for(int i=0; i<n; i++)
//         {
//             for(int j=i+1; j<n; j++)
//             {
//                 set<long long> hashset;
//                 for(int k=j+1; k<n; k++)
//                 {
//                     // Just for practice : ChatGpt pr aise likhi hui thi ye line  
//                     // long long sum = (long long)nums[i] + nums[j] + nums[k];
//                     long long sum = nums[i] + nums[j];
//                     sum += nums[k];
//                     // Just for practice : ChatGpt pr aise likhi hui thi ye line
//                     // long long fourth = (long long)target - sum;
//                     long long fourth = target - sum;
//                     if(hashset.find(fourth) != hashset.end())
//                     {
//                         vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
//                         sort(temp.begin(), temp.end());
//                         st.insert(temp);
//                     }

//                     // 👇 Example:

//                     // nums = [1, 2, 3, 4, 5]
//                     // target = 10

//                     // Maan lo:

//                     // i = 0 (nums[i] = 1)
//                     // j = 1 (nums[j] = 2)
//                     // Ab loop chal raha hai k = 2 to n-1

//                     // k = 2 (nums[k] = 3)
//                     // sum = 1 + 2 + 3 = 6

//                     // fourth = 10 - 6 = 4

//                     // hashset is empty → 4 nahi mila

//                     // insert 3 into hashset

//                     // k = 3 (nums[k] = 4)
//                     // sum = 1 + 2 + 4 = 7

//                     // fourth = 3

//                     // Ab 3 hashset mein hai → YES!
//                     // => Ek valid quadruplet mil gaya: [1, 2, 4, 3]

//                     hashset.insert(nums[k]);
//                 }
//             }
//         }
//         vector<vector<int>> ans(st.begin(), st.end());
//         return ans;
//     }
// };

// Time Complexity:
// Outer loops (i, j, k) run in O(N^3) time.
// Inside the innermost loop, we use a hashset to check if the "fourth" number exists.
// In the worst case, this lookup is:
//   - O(1) for unordered_set
//   - O(log M) for set (M = number of elements in set so far)

// If we use set<vector<int>> to avoid duplicates, insertion into this set takes O(log Q),
// where Q = number of unique quadruplets found.

// Therefore:
// Total Time Complexity = O(N^3) * O(log Q)

// Note: Temporary array of size 4 is created each time (which is constant), so its cost is negligible in Big-O.
// Final Time Complexity: O(N^3 * log Q)


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    
        int n = nums.size();
        vector<vector<int>> ans;
        
        // Sort the array to use two-pointer approach and handle duplicates
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++)
        {
            // Skip duplicate values for i
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1; j<n; j++)
            {
                // Skip duplicate values for i
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                
                // Two-pointer setup
                int k = j+1;
                int l = n-1;
                while(k<l)
                {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    // If sum matches the target, we found a valid quadruplet
                    if(sum == target){
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;    // Move third pointer forward
                        l--;    // Move fourth pointer backward    
                        // Skip duplicate values for k
                        while(k<l && nums[k] == nums[k-1]) k++;
                        // Skip duplicate values for l
                        while(k<l && nums[l] == nums[l+1]) l--;
                    }
                    else if(sum < target) k++;
                    else l--;
                }
            }
        }
        return ans;
    }
};

// Time Complexity:
// Sorting: O(n log n)
// First loop i: runs n times
// Second loop j: runs up to n times (nested)
// Inner while loop using two pointers: each pair (k, l) can traverse the rest → O(n)
// #_Time Complexity = O(n^3)


// Space Complexity:
// We're only using the result vector ans to store quadruplets.
// No extra space like sets or hashmaps is used.
// Space Complexity = O(number of unique quadruplets)

// Short Summary:
// Aspect	            Complexity
// Time Complexity	    O(n^3)
// Space Complexity	O(# of quads)
