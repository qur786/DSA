class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        stack<int> st;
        int totalWater = 0;

        for (int right = 0; right < size; right++) {
            while (!st.empty() && height[st.top()] < height[right]) {
                int currentIndex = st.top();
                st.pop();

                if (st.empty())
                    break;

                int minHeight = min(height[right], height[st.top()]);
                int width = right - st.top() - 1;

                totalWater += width * (minHeight - height[currentIndex]);
            }
            st.push(right);
        }

        return totalWater;
    }
};