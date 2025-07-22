// Extra question:
// https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
// Longest Substring with K Uniques
// YT : https://www.youtube.com/watch?v=teM9ZsVRQyc&t=298s

// class Solution {
//   public:
//     int longestKSubstr(string &s, int k) {

//         int maxlength = -1;     // Agar aap maxlength = 0 loge: Ye tab theek hai jab aapko guarantee ho ki kam se kam ek valid substring milegi jisme exactly k unique characters ho.
//         int n = s.size();
//         unordered_map<char, int> mpp;
        
//         for(int i=0; i<n; i++)
//         {
//             mpp.clear();    // mpp ek unordered_map hai jo current substring ke characters ko store karta hai. Jab aap outer loop ka i badhate ho (naya substring start karte ho), toh purane characters map me reh jaate hain agar clear() nahi kiya.
//             for(int j=i; j<n; j++)
//             {
//                 mpp[s[j]]++;
//                 if(mpp.size() == k)
//                 {
//                     maxlength = max(maxlength, j-i+1);
//                 }
//                 else if(mpp.size() > k)
//                 {
//                     break;
//                 }
//             }
//         }
//         return maxlength;
//     }
// };

// Time Complexity (TC) = O(n^2)
// Explanation:
//  - Outer loop runs n times.
//  - Inner loop runs up to n times for each outer iteration.
//  - Each insertion/access in map takes O(1) on average (unordered_map).

// So overall:
// TC = O(n^2) * O(1) = O(n^2)  (for unordered_map)

// If using ordered map (like map<char, int>), then:
// TC = O(n^2) * O(log 26) = O(n^2) * O(1) (since log 26 is constant for lowercase letters)

// Space Complexity (SC):
// - Maximum 256 characters in extended ASCII.
// - SC = O(256) = O(1) (constant space)

                    // Optimise 
// class Solution {
//   public:
//     int longestKSubstr(string &s, int k) {
//         // your code here
//         int maxlength = -1;
//         int right = 0;
//         int left = 0;
//         unordered_map<char, int> mpp;
        
//         while(right < s.size())
//         {
//             mpp[s[right]]++;
            
//             while(mpp.size() > k)
//             {
//                 mpp[s[left]]--;
//                 if(mpp[s[left]] == 0) {
//                     mpp.erase(s[left]);
//                 }
//                 left = left + 1;
//             }
            
//             if(mpp.size() == k)
//             {
//                 maxlength = max(maxlength, right- left + 1);
//             }
            
//             right = right + 1;
//         }
        
//         return maxlength;
//     }
// };

// TC = O(N) + O(N) + O(log 256)
// Sc = O(256)
// Time Complexity: O(n), where n = length of string
// Space Complexity: O(k), for storing up to k unique characters in the map


                // more optomised
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // your code here
        int maxlength = -1;
        int right = 0;
        int left = 0;
        unordered_map<char, int> mpp;
        
        while(right < s.size())
        {
            mpp[s[right]]++;
            
            if(mpp.size() > k)
            {
                mpp[s[left]]--;
                if(mpp[s[left]] == 0) {
                    mpp.erase(s[left]);
                }
                left = left + 1;
            }
            
            if(mpp.size() == k)
            {
                maxlength = max(maxlength, right- left + 1);
            }
            
            right = right + 1;
        }
        
        return maxlength;
    }
};

// TC = O(N) + O(log 256)
