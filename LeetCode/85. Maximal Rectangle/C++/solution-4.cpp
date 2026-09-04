class Solution {
private:
    int calculateMaxRectangle(vector<int>& heights) {
        heights.push_back(INT_MIN);
        int size = heights.size();
        stack<int> st;
        int maxRectangle = 0;

        for (int right = 0; right < size; right++) {
            while (!st.empty() && (heights[st.top()] > heights[right])) {
                int currentIndex = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int width = right - left - 1;
                int height = heights[currentIndex];
                maxRectangle = max(maxRectangle, width * height);
            }
            st.push(right);
        }
        heights.pop_back();

        return maxRectangle;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxRectangle = 0;

        for (const auto& row : matrix) {
            for (int i = 0; i < cols; i++) {
                if (row[i] == '0')
                    heights[i] = 0;
                else
                    heights[i] += 1;
            }
            maxRectangle = max(maxRectangle, calculateMaxRectangle(heights));
        }

        return maxRectangle;
    }
};