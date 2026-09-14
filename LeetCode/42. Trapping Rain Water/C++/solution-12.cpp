class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        stack<int> st;
        long long totalWater = 0;

        for (int i = 0; i < size; i++) {
            while (!st.empty() && (height[i] > height[st.top()])) {
                int currentIndex = st.top();
                st.pop();
                if (!st.empty()) {
                    int w = (i - st.top() - 1);
                    int h =
                        min(height[st.top()], height[i]) - height[currentIndex];
                    totalWater += (long long)w * h;
                }
            }
            st.push(i);
        }

        return totalWater;
    }
};