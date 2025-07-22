// 25.
// https://leetcode.com/problems/running-sum-of-1d-array/description/
// 1480. Running Sum of 1d Array

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
		int n = nums.size();
		vector<int> prefix(n,0); //TC - O(N) //vector of int naame prefix array banaya jiske sare element zero h 
		int sum = 0;

		// 1 2 3 4
			// sum = 0 + 1 = 1, prefix[0] = 1
			// sum = 1 + 2 = 3, prefix[1] = 3
			// sum = 3 + 3 = 6, prefix[2] = 6
			// sum = 6 + 4 = 10, prefix[1] = 10
			
		for(int i=0; i<n; i++){		//TC - O(N)
			sum = sum + nums[i];
			prefix[i] = sum;
		}
		return prefix;
	}
};

// Example of Prefix array
//  				1   2    3    4    5
// Prefix array:	1   3    6    10   15

// Example of suffix array
// 				1    2    3    4   5
// suffix array :  15   14   12   9   5

// Time complexity - O(N)
// Space complexity - O(N)
