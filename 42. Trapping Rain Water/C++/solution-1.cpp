class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax = INT_MIN, rightMax = INT_MIN;
        int left = 0, right = height.size() - 1;
        int totalWater = 0;

        while (left < right) {
            if (height[left] <= height[right]) {
                leftMax = max(leftMax, height[left]);
                totalWater += leftMax - height[left];
                left++;
            } else {
                rightMax = max(rightMax, height[right]);
                totalWater += rightMax - height[right];
                right--;
            }
        }

        return totalWater;
    }
};