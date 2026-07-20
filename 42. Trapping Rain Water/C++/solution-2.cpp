class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int size = height.size(), totalWater = 0;

        for (int i = 0; i < size; i++) {
            while (!st.empty() && height[st.top()] < height[i]) {
                int bottomHeight = height[st.top()];
                st.pop();
                if (st.empty())
                    break;
                int rightBoundry = height[i];
                int leftBoundry = height[st.top()];
                int width = i - st.top() - 1;
                totalWater +=
                    width * (min(leftBoundry, rightBoundry) - bottomHeight);
            }
            st.push(i);
        }

        return totalWater;
    }
};