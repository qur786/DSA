class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax = height[0], rightMax = height.back();
        int left = 0, right = height.size() - 1;
        int totalWater = 0;

        while (left < right) {
            if (height[left] <= height[right]) {
                leftMax = max(height[left], leftMax);
                totalWater += leftMax - height[left];
                left++;
            } else {
                rightMax = max(height[right], rightMax);
                totalWater += rightMax - height[right];
                right--;
            }
        }

        return totalWater;
    }
};