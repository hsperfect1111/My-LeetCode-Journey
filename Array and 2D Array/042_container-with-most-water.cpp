// 42.
// https://leetcode.com/problems/container-with-most-water/description/
// 11. Container With Most Water
// YT : https://www.youtube.com/watch?v=w7ftYsZtIbs

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while(left < right)
        {
            int area = min(height[left], height[right]) * (right - left);
            maxArea = max(area, maxArea);

            if(height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return maxArea;
    }
};