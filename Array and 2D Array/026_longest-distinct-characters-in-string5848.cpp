// 26.
// https://www.geeksforgeeks.org/problems/longest-distinct-characters-in-string5848/1
// Longest substring with distinct characters

// class Solution {
//   public:
//     int longestUniqueSubstr(string &s) {
//         int maxlength = 0;
//         int n = s.size();
//         for(int i=0; i<n; i++)
//         {
//             int hash[256] = {0};
//             for(int j=i; j<n; j++)
//             {
//                 if(hash[s[j]] == 1) break;
//                 hash[s[j]] = 1;
//                 maxlength = max(maxlength, j-i+1);
//             }
//         }
//         return maxlength;
//     }
// };

// TC = O(N^2)
// Sc = O(256)

//NOTE : On any problem which involves finding max substring or something like that you should thinking two pointer and a slinding window approach

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // There are 256 characters so, not define map data structure because that will be taking logarithmic time so we use hash array of 256 initialized with -1.
        
        // Using hash array of 256 (ASCII) initialized with -1
         
        int hash[256];
        fill_n(hash, 256, -1);
        int n = s.size();
        int l=0, r=0, maxlength=0;
        
        while(r<n)
        {
            if(hash[s[r]] != -1 && hash[s[r]] >= l)
            {
                l = hash[s[r]] + 1;
            }
            maxlength = max(maxlength, r-l+1);
            
            // This line records the most recent index where the character s[r] appeared.
            // So if we ever see this character again later in the string, we can quickly know where it was last seen.
            // This is what allows us to "jump" the left pointer (l) forward, instead of moving it one-by-one.
            
            // Let's say s = "abcabcbb"
            // Initially: l = 0, r = 0
            // We see 'a', store hash['a'] = 0, move r to 1
            // We see 'b', store hash['b'] = 1, move r to 2
            // We see 'c', store hash['c'] = 2, move r to 3
            // We see 'a' again at r = 3:
            // It's already in hash, and its last index (0) is within the current window (l = 0)
            // So we shift l = 0 + 1 = 1
            // Then we update hash['a'] = 3 (the new index of 'a')
                        
            hash[s[r]] = r;
            r++;
        }
        
        return maxlength;
        
    }
};

// Time Complexity: O(N)
// Space Complexity: O(256) (for ASCII)
// Efficiency: ptimal and recommended.
// Extra Point: You're smart to use hash[s[r]] >= l, which ensures you only shift l forward, never backward.
