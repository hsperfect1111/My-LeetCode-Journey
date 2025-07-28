// 28.
// https://leetcode.com/problems/rotate-array/description/
// 189. Rotate Array

//Make Notes:
//Optimal Approach:
class Solution {
public:

	void reverse(vector<int> &nums, int start, int end){
		while(start < end)
		{
			int temp = nums[start];
			nums[start] = nums[end];
			nums[end] = temp;

			start++;
			end--;
		}
	}

    void rotate(vector<int>& nums, int k)
	{
        int n = nums.size();
        k = k % n;

		// reverse entire array
		reverse(nums, 0, n-1);  // T.C = O(N)

		// reverse first k elements             [Total // T.C of
        reverse(nums, 0, k-1);  // T.C = O(k)       this two fun is
                                                    // T.C = O(N)
		// reverse last n-k elements
        reverse(nums, k, n-1);     // T.C = O(N-k)          ]
	}
};

// Reverse : use Two pointer approach Aur iski Time complexity O(N).
// Space Complexity = O(1).

// nums = [1,2,3,4,5,6,7] , k=3
// 		   7,6,5,4,3,2,1
// 		5,6,7		1,2,3,4		// [ 0-(3-1) ] Reverse kr dege [3-( n-1 )] tk Reverse kr dege.

//Total T.C = O(N+k+N-k)  // T.C = O(2N) // T.C = O(N)

