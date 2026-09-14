class Solution {
public:
    int trap(vector<int>& height) {
        long long totalWater = 0;
        int size = height.size();
        int leftMax = 0, rightMax = 0;
        int left = 0, right = size - 1;

        while (left <= right) {
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