class Solution {
private:
    long long getMaxSum(vector<int>& nums) {
        long long sum = 0;
        nums.push_back(INT_MAX);
        int size = nums.size();
        stack<int> st;

        for (int right = 0; right < size; right++) {
            while (!st.empty() && (nums[st.top()] < nums[right])) {
                int currentIndex = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                long long w1 = right - currentIndex;
                long long w2 = currentIndex - left;
                sum += w1 * w2 * (nums[currentIndex]);
            }
            st.push(right);
        }
        nums.pop_back();

        return sum;
    }
    long long getMinSum(vector<int>& nums) {
        long long sum = 0;
        nums.push_back(INT_MIN);
        int size = nums.size();
        stack<int> st;

        for (int right = 0; right < size; right++) {
            while (!st.empty() && (nums[st.top()] > nums[right])) {
                int currentIndex = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                long long w1 = right - currentIndex;
                long long w2 = currentIndex - left;
                sum += w1 * w2 * (nums[currentIndex]);
            }
            st.push(right);
        }
        nums.pop_back();

        return sum;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        return getMaxSum(nums) - getMinSum(nums);
    }
};