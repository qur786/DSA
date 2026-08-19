class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        arr.push_back(INT_MIN); // Santient value
        int size = arr.size();
        stack<int> st;
        long long sum = 0;
        int MOD = 1e9 + 7;

        for (int right = 0; right < size; right++) {
            while (!st.empty() && (arr[right] < arr[st.top()])) {
                int currentIndex = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int leftWidth = currentIndex - left;
                int rightWidth = right - currentIndex;
                sum += (long long)leftWidth * rightWidth * arr[currentIndex];
            }
            st.push(right);
        }

        arr.pop_back();

        return sum % MOD;
    }
};