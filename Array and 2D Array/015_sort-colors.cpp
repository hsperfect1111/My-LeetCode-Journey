15.
https://leetcode.com/problems/sort-colors/description/
75. Sort Colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
		int one = 0;

		int n = nums.size();

		for(int i=0; i<n; i++){
			if(nums[i] == 0){
				zero++;
			}
			else if(nums[i] == 1){
				one++;
			}
		}

        // Fills the first zero elements of the array with 0.
		int i=0;
		while(i < zero)
		{
			nums[i] = 0;
			i++;
		}

		// 1 0 0 0
		// 0 0 0

        // After writing all the 0s, the next segment of the array should be all 1s.
		while(i < (one+zero)) 
		{
			nums[i] = 1;
			i++;
		}

        // Whatever remains after placing 0s and 1s must be 2s, so this loop fills the rest of the array with 2s.
		while(i<n)
		{
			nums[i] = 2;
			i++;
		}
    }
};

// Time complexity: O(n) – you iterate through the array a few times.
// Space complexity: O(1) – in-place sorting, only a few variables used.
