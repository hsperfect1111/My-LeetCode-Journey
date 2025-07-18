https://www.geeksforgeeks.org/problems/max-distance-between-same-elements/1
Max distance between same elements
YT : https://www.youtube.com/watch?v=CwU2oflKEjQ

class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code here
        int n = arr.size();
        unordered_map<int, int> m;
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(m.find(arr[i]) != m.end())
            {
                ans = max(ans,i-m[arr[i]]);
            }
            else
            m.insert({arr[i], i});
        }
        return ans;
    }
};


// Time Complexity (TC) :
// Inside the loop:
// m.find(arr[i]) is O(1) average time using unordered_map.
// m.insert({arr[i], i}) is also O(1) on average.
// So, each iteration takes constant time → O(1).
// Hence, Total Time Complexity = O(n)

// Space Complexity (SC) :
// The map unordered_map<int, int> m stores only the first occurrence index of each distinct element in arr.
// In the worst case, all elements in the array are distinct → the map stores n entries.
// Each entry takes constant space.
// So, Space Complexity = O(n) in the worst case.
