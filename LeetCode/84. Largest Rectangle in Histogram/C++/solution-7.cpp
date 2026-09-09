class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(INT_MIN);
        int size = heights.size();
        stack<int> st;
        long long largestRectangle = 0;

        for (int i = 0; i < size; i++) {
            while (!st.empty() && (heights[i] < heights[st.top()])) {
                int currentIndex = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                largestRectangle =
                    max(largestRectangle,
                        (long long)heights[currentIndex] * (i - left - 1));
            }
            st.push(i);
        }
        heights.pop_back();

        return largestRectangle;
    }
};