class Solution {
public:
    int getMaximalRectangle(vector<int>& heights) {
        heights.push_back(0); // santient value;
        int size = heights.size();
        stack<int> monotonicIncreasingHeightIndices;
        int maxArea = 0;

        for (int right = 0; right < size; right++) {
            while (!monotonicIncreasingHeightIndices.empty() &&
                   heights[monotonicIncreasingHeightIndices.top()] >
                       heights[right]) {
                int currentIndex = monotonicIncreasingHeightIndices.top();
                monotonicIncreasingHeightIndices.pop();
                int left = monotonicIncreasingHeightIndices.empty()
                               ? -1
                               : monotonicIncreasingHeightIndices.top();
                int height = heights[currentIndex];
                int width = right - left - 1;

                maxArea = max(maxArea, height * width);
            }
            monotonicIncreasingHeightIndices.push(right);
        }

        heights.pop_back();

        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<int> heights(col, 0);
        int maxRectangle = 0;

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                heights[c] = matrix[r][c] == '0' ? 0 : (heights[c] + 1);
            }
            maxRectangle = max(maxRectangle, getMaximalRectangle(heights));
        }

        return maxRectangle;
    }
};