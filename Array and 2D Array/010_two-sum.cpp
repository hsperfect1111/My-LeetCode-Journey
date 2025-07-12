// 10.
// https://leetcode.com/problems/two-sum/description/
// 1. Two Sum
// YT : https://www.youtube.com/watch?v=UXDSeD9mN-k

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         // Brute Force 
//         int n = nums.size();
//         for(int i=0; i<n; i++)
//         {
//             for(int j=0; j<n; j++)
//             {
//                 if(i == j) continue;
//                 if(nums[i] + nums[j] == target)
//                 {
//                     // return yes;
//                     return {i,j};

//                 }
//             }
//         }
//         return {};
//     }
// };

// TC + O(n^2)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Better Solution : Using hashing
        map<int, int> mp;   // value -> index
        int n = nums.size();

        for(int i=0; i<n; i++)
        {
            int a = nums[i];
            int more = target - a;
            // map.find(key) : Yeh function check karta hai ki key (yahan more) map ke andar hai ya nahi.
            // Agar mil gaya, toh yeh iterator return karta hai us key ke position pe.
            // Agar nhi mila to continue karo
                // nums = [2, 7, 11, 15]
                // target = 9
                // 1. i = 0 → a = 2 → more = 9 - 2 = 7
                // mp.find(7) == mp.end() → false
                // So 7 map mein nahi hai, continue
            // Agar nahi mila, toh yeh return karta hai: mp.end() (matlab "kahi nahi mila").
            if(mp.find(more) != mp.end())
            {
                return {mp[more], i};   // return "YES";   
            }

            // mp[a] = i; ka kaam:
            // Store karna: current number a ko map mein as a key, aur uska index i as value.
            // Store the current number with its index
                // nums = [2, 7, 11, 15];
                // jab i = 0 hoga:
                // a = nums[0] = 2;
                // mp[2] = 0;
                // Matlab map ab ye dikhata hai:
                // mp = { 2 → 0 }
            mp[a] = i;
        }
        return {};  // return "NO"; // return empty vector if no solution found
    }
};

// TC = O(N*logn) if map works in logarithimic than it's this.
// TC = O(N) if you're assuming the map to work in O(1)
// O(N) when we take a unordered_map in the best and avg case 
// In the worst case unorder_map it can go uptoO(n^2)
// SC = O(N)

// NOTE : Ye code bs Yes or no return krne k liye h is wale question m idx return kr rahe h uske liye nhi h uske liye Better Solution best h.
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         // Best Solution : Using two-pointer approach / greedy approach
//         int left = 0;
//         int right = nums.size() - 1;
//         while(left < right)
//         {
//             int sum = nums[left] + nums[right];
//             if(sum == target)
//             {
//                 return "Yes"
//             }
//             else if(sum < target) left++;
//             else right--;
//         }
//         return "No";
// };

// TC = O(N)
// TC = O(N) + O(Nlogn) for sorting
// SC = O(1) if change array than O(N)
