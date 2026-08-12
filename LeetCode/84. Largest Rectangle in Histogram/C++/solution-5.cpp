class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        deque<int> dq;
        heights.push_back(INT_MIN);
        int size = heights.size();
        long long maxArea = 0;

        for (int right = 0; right < size; right++) {
            while (!dq.empty() && heights[right] < heights[dq.back()]) {
                int currentIndex = dq.back();
                dq.pop_back();
                int left = dq.empty() ? -1 : dq.back();
                int height = heights[currentIndex];
                int width = right - left - 1;
                maxArea = max(maxArea, (long long)height * width);
            }
            dq.push_back(right);
        }

        heights.pop_back();

        return maxArea;
    }
};