class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> input(cols, 0);
        input.push_back(INT_MIN);
        int maxRectangle = INT_MIN;

        for (int row = 0; row < rows; row++) {
            stack<int> st;
            for (int right = 0; right <= cols; right++) {
                if (right < cols)
                    input[right] =
                        matrix[row][right] == '0'
                            ? 0
                            : (input[right] + (matrix[row][right] - '0'));
                while (!st.empty() && (input[right] < input[st.top()])) {
                    int currentIndex = st.top();
                    st.pop();
                    int left = st.empty() ? -1 : st.top();
                    int w = right - left - 1;
                    int h = input[currentIndex];
                    maxRectangle = max(maxRectangle, w * h);
                }
                st.push(right);
            }
        }

        return maxRectangle;
    }
};