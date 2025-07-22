// Extra Question:
// https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/1618723478/
// 3. Longest Substring Without Repeating Characters
// Yt : https://www.youtube.com/watch?v=-zSxTJkcdAo

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int maxlength = 0;
//         int n = s.size();
//         for(int i=0; i<n; i++)
//         {
//             int hash[256] = {0};
//             for(int j=i; j<n; j++)
//             {
//                 if(hash[s[j]] == 1) break;  // Repeating character found
//                 hash[s[j]] = 1; // Mark character as seen
//                 int length = j-i+1;
//                 maxlength = max(maxlength, length);
                
//             }
//         }
//         return maxlength;
//     }
// };

// TC = O(N^2)
// Sc = O(256)

// on any problem which involves finding max substring or something like that you should thinking two pointer and a slinding window approach
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // There are 256 characters so, not define map data structure because that will be taking logarithmic time so we use hash array of 256 initialized with -1.
        // Using hash array of 256 (ASCII) initialized with -1
        int hash[256];
        fill_n(hash, 256, -1);  // Initialize all values to -1
        int n = s.size();
        int l=0, r=0, maxlength=0;

        while(r<n)
        {
            if(hash[s[r]] != -1)    // In the map
            {
                //IMp 20:38
                if(hash[s[r]] >= l)
                {
                    l = hash[s[r]] + 1;
                }
            }
            int length = r-l+1;
            maxlength = max(maxlength, length);

            hash[s[r]] = r;
            r++;
        }
        return maxlength;
    }
};

// Tc = O(n)
// Sc = O(256)
