class Solution {
private:
    int getMaxRectangle(vector<int>& heights) {
        heights.push_back(INT_MIN);
        int size = heights.size();
        stack<int> st;
        int maxHeight = 0;

        for (int i = 0; i < size; i++) {
            while (!st.empty() && (heights[i] < heights[st.top()])) {
                int currentIndex = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int h = heights[currentIndex];
                int w = i - left - 1;
                maxHeight = max(maxHeight, w * h);
            }
            st.push(i);
        }

        heights.pop_back();

        return maxHeight;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxHeight = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                heights[j] = matrix[i][j] == '1' ? (heights[j] + 1) : 0;
            maxHeight = max(maxHeight, getMaxRectangle(heights));
        }

        return maxHeight;
    }
};