// https://leetcode.com/problems/majority-element/
// 169. Majority Element
// Yt : https://www.youtube.com/watch?v=wD7fs5P_MVo

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int count = 0;
        int answer = -1;

        for(int i=0; i<nums.size(); i++){
            if(count == 0){
                answer = nums[i];
                count = 1;
            }
            else
            {
                if(answer == nums[i])
                {
                    count++;
                }
                else
                {
                    count--;
                }
            }
        }
        return answer;
    }
};

// TC = O(n)
// SC = O(1)
