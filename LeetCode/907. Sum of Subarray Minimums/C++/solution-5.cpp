class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        arr.push_back(INT_MIN); // Santient value
        int size = arr.size();
        stack<int> st;
        int MOD = 1e9 + 7;
        long long sum = 0;

        for (int right = 0; right < size; right++) {
            while (!st.empty() && (arr[st.top()] > arr[right])) {
                int currentIndex = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int rightW = right - currentIndex;
                int leftW = currentIndex - left;

                sum += (long long)arr[currentIndex] * rightW * leftW;
            }
            st.push(right);
        }

        arr.pop_back();

        return sum % MOD;
    }
};