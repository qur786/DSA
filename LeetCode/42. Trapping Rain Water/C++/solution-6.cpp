class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> monotonicDecreasingHeightIndices;
        int size = height.size(), totalTrappedWater = 0;

        for (int right = 0; right < size; right++) {
            while (!monotonicDecreasingHeightIndices.empty() &&
                   height[monotonicDecreasingHeightIndices.top()] <
                       height[right]) {
                int boundaryIndex = monotonicDecreasingHeightIndices.top();
                monotonicDecreasingHeightIndices.pop();
                if (monotonicDecreasingHeightIndices.empty())
                    break;
                int left = monotonicDecreasingHeightIndices.top();
                int w = right - left - 1;
                int h =
                    min(height[left], height[right]) - height[boundaryIndex];
                totalTrappedWater += w * h;
            }
            monotonicDecreasingHeightIndices.push(right);
        }

        return totalTrappedWater;
    }
};