class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0); // Santient value to trigger the loop again for
                              // any values remaining in the stack
        int size = heights.size();
        int maxArea = 0;

        for (int i = 0; i < size; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int top = st.top();
                st.pop();
                int height = heights[top];
                int width = st.empty() ? i : i - st.top() - 1;

                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        heights.pop_back();

        return maxArea;
    }
};