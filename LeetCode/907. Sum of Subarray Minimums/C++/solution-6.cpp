class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9 + 7;
        arr.push_back(INT_MIN);
        int size = arr.size();
        long long sum = 0;
        stack<int> st;

        for (int right = 0; right < size; right++) {
            while (!st.empty() && (arr[right] < arr[st.top()])) {
                int currentIndex = st.top(); st.pop();
                int left = st.empty() ? -1 : st.top();
                long long w1 = right - currentIndex;
                long long w2 = currentIndex - left;
                sum += (w1 * w2 * (long long)arr[currentIndex]);
            }
            st.push(right);
        }

        arr.pop_back();

        return sum % mod;
    }
};