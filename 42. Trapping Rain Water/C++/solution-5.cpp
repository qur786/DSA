class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> decreasingHeights;
        int trappedWater = 0, size = height.size();

        for (int i = 0; i < size; i++) {
            while (!decreasingHeights.empty() &&
                   height[decreasingHeights.top()] < height[i]) {
                int bottomHeight = height[decreasingHeights.top()];
                decreasingHeights.pop();

                if (decreasingHeights.empty())
                    break;

                int width = i - decreasingHeights.top() - 1;
                trappedWater +=
                    width * (min(height[i], height[decreasingHeights.top()]) -
                             bottomHeight);
            }
            decreasingHeights.push(i);
        }

        return trappedWater;
    }
};