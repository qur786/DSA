class Solution {
private:
    long long sumOfMinimums(vector<int>& nums) {
        nums.push_back(INT_MIN);
        int size = nums.size();
        long long sum = 0;
        stack<int> st;

        for (int right = 0; right < size; right++) {
            while (!st.empty() && (nums[right] < nums[st.top()])) {
                int currentIndex = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int rightW = right - currentIndex;
                int leftW = currentIndex - left;
                sum += (long long)leftW * rightW * nums[currentIndex];
            }
            st.push(right);
        }
        nums.pop_back();

        return sum;
    }
    long long sumOfMaxmimums(vector<int>& nums) {
        nums.push_back(INT_MAX);
        int size = nums.size();
        long long sum = 0;
        stack<int> st;

        for (int right = 0; right < size; right++) {
            while (!st.empty() && (nums[right] > nums[st.top()])) {
                int currentIndex = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int rightW = right - currentIndex;
                int leftW = currentIndex - left;
                sum += (long long)leftW * rightW * nums[currentIndex];
            }
            st.push(right);
        }
        nums.pop_back();

        return sum;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        return sumOfMaxmimums(nums) - sumOfMinimums(nums);
    }
};