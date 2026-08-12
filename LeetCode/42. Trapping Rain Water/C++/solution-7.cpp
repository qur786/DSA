class Solution {
public:
    int trap(vector<int>& height) {
        int totalTrappedWater = 0;
        int size = height.size();
        stack<int> monotonicDecreasingHeightIndices;

        for (int right = 0; right < size; right++) {
            while (!monotonicDecreasingHeightIndices.empty() &&
                   height[monotonicDecreasingHeightIndices.top()] <
                       height[right]) {
                int currentIndex = monotonicDecreasingHeightIndices.top();
                monotonicDecreasingHeightIndices.pop();

                if (monotonicDecreasingHeightIndices.empty())
                    break;

                int left = monotonicDecreasingHeightIndices.empty()
                               ? -1
                               : monotonicDecreasingHeightIndices.top();

                int h = min(height[monotonicDecreasingHeightIndices.top()],
                            height[right]) -
                        height[currentIndex];
                int w = right - left - 1;

                totalTrappedWater += w * h;
            }
            monotonicDecreasingHeightIndices.push(right);
        }

        return totalTrappedWater;
    }
};