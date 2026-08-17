class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        stack<int> monotonicDecreasingSt;
        int totalWater = 0;

        for (int right = 0; right < size; right++) {
            while (!monotonicDecreasingSt.empty() &&
                   height[right] > height[monotonicDecreasingSt.top()]) {
                int currentIndex = monotonicDecreasingSt.top();
                monotonicDecreasingSt.pop();

                int w = monotonicDecreasingSt.empty()
                            ? 0
                            : right - monotonicDecreasingSt.top() - 1;
                int h = monotonicDecreasingSt.empty()
                            ? 0
                            : (min(height[right],
                                   height[monotonicDecreasingSt.top()]) -
                               height[currentIndex]);

                totalWater += w * h;
            }

            monotonicDecreasingSt.push(right);
        }

        return totalWater;
    }
};