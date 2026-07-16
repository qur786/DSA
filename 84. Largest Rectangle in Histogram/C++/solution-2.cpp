class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int size = heights.size(), maxArea = 0;
        stack<int> st;

        for (int i = 0; i < size; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int top = st.top();
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                int height = heights[top];
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        heights.pop_back();

        return maxArea;
    }
};