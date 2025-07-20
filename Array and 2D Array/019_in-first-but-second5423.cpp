// 19.
// https://www.geeksforgeeks.org/problems/in-first-but-second5423/1
// Find missing in second array
// YT : https://www.youtube.com/watch?v=nwT1jiXdbXk


class Solution {

  public:
    vector<int> findMissing(vector<int>& a, vector<int>& b) {

        // Create a hash map to store frequency of elements in array b
        unordered_map <int, int> mp;
        for(int i=0; i<b.size(); i++)
        {
            mp[b[i]]++; // Count frequency of each element in b
        }
        
        
        vector<int> ans;
        for(int i=0; i<a.size(); i++)
        {
            // If the element from a is not found in b (i.e., count is zero)
            if(mp[a[i]] == 0)
            {
                ans.push_back(a[i]);    // Add it to the result
            }
        }
        return ans;
    }
};
