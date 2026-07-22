class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> monotoniqueIncreasingHeightIndices;
        heights.push_back(INT_MIN); // santient value
        int size = heights.size();
        int maxArea = 0;

        for (int i = 0; i < size; i++) {
            while (!monotoniqueIncreasingHeightIndices.empty() &&
                   heights[monotoniqueIncreasingHeightIndices.top()] >
                       heights[i]) {
                int height = heights[monotoniqueIncreasingHeightIndices.top()];
                monotoniqueIncreasingHeightIndices.pop();
                int width =
                    monotoniqueIncreasingHeightIndices.empty()
                        ? i
                        : i - monotoniqueIncreasingHeightIndices.top() - 1;

                maxArea = max(maxArea, height * width);
            }
            monotoniqueIncreasingHeightIndices.push(i);
        }

        heights.pop_back();

        return maxArea;
    }
};