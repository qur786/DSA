class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> monotonicIncreasingHeightsIndex;
        heights.push_back(INT_MIN); // santient value
        int maxArea = 0;
        int size = heights.size();

        for (int i = 0; i < size; i++) {
            while (!monotonicIncreasingHeightsIndex.empty() &&
                   heights[monotonicIncreasingHeightsIndex.top()] >
                       heights[i]) {
                int currentIndex = monotonicIncreasingHeightsIndex.top();
                monotonicIncreasingHeightsIndex.pop();
                int left = monotonicIncreasingHeightsIndex.empty()
                               ? -1
                               : monotonicIncreasingHeightsIndex.top();
                int right = i;
                int height = heights[currentIndex];
                int width = right - left - 1;
                int area = width * height;
                maxArea = max(maxArea, area);
            }
            monotonicIncreasingHeightsIndex.push(i);
        }

        return maxArea;
    }
};