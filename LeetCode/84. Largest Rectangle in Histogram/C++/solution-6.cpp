class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(INT_MIN); // Santient value
        int size = heights.size();
        stack<int> st;
        int maxRectangle = 0;

        for (int right = 0; right < size; right++) {
            while (!st.empty() && heights[st.top()] > heights[right]) {
                int currentIndex = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int w = right - left - 1;
                int h = heights[currentIndex];
                maxRectangle = max(maxRectangle, w * h);
            }
            st.push(right);
        }

        heights.pop_back();

        return maxRectangle;
    }
};