// 22.
// https://leetcode.com/problems/move-zeroes/description/
// 283. Move Zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // int n = nums.size();
        //int arr[n] = {0}; concept : First idx pr zero aa jayega aur baki sbpr bhi 0 aa jayega
        //int arr[n] = {7}; // idx[0] pr a gaya 7 baki sb pr aa gaya zero       
        //int arr[n] = {0,1}; // iska mtlb h idx[0] pr aa gaya 0 aur idx[1] pr aa gaya 1
        //int arr[n] = {0,1,6}; // idx[0] pr aa gaya 0 aur idx[1] pr aa gaya 1 aur idx[2] pr aa gaya 6.

        // int n = nums.size();
        // int arr[n];
        // for(int i=0; i<n; i++){
        //     arr[i] = 0;
        // }
        // int j=0; // Imp variable j tracks where the next non-zero element should be placed in the temporary array (arr).
        // for(int i=0; i<n; i++){
        //     if(nums[i] != 0){
        //         arr[j] = nums[i];
        //         j++;
        //     }
        // }
        // for(int i=0; i<n; i++){
        //     nums[i] = arr[i]; //Imp 1:42:52
        // }

        //Optimal solution
        int n = nums.size();
		int frnd = 0;
		for(int me=0; me<n; me++){
			if(nums[me] != 0){
				swap(nums[me] , nums[frnd]);
				frnd++;
			}
		}
    }
};
