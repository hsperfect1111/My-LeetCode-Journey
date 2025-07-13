// 9.
// https://leetcode.com/problems/range-sum-query-immutable/description/
// 303. Range Sum Query - Immutable

//Make Notes form video for this Question:

class NumArray {
public:

	vector<int> prefix;
    NumArray(vector<int>& nums) { //ye ek constructor de rakha h jiske andar hume initialize wala part krna hota h
        
		int n = nums.size();
		prefix.resize(n, 0);//prefix ko resixe kr diya //iska size n aur sare element ko zero kr diya 

		int sum = 0;
		for(int i=0; i<n; i++){
			sum = sum + nums[i];
			prefix[i] = sum;
		}
    }

	//0 -- 3

	//1 -- 3
	//prefix[3] = nums[0] + nums[1] + nums[2] + nums[0]
    
    int sumRange(int left, int right) {
        if(left == 0)
		{
			return prefix[right];
		}
		else
		{
			return prefix[right] - prefix[left-1];
		}
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
