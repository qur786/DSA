class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long sum = 0;
        constexpr int MOD = 1e9 + 7;
        stack<int> monotonicIncreasingArrayIndices;
        arr.push_back(INT_MIN); // Santient value
        int size = arr.size();

        for (int right = 0; right < size; right++) {
            while (!monotonicIncreasingArrayIndices.empty() &&
                   arr[monotonicIncreasingArrayIndices.top()] > arr[right]) {
                int currentIndex = monotonicIncreasingArrayIndices.top();
                monotonicIncreasingArrayIndices.pop();
                long long rightSubArrayWidth = right - currentIndex;
                long long leftSubArrayWidth =
                    currentIndex -
                    (monotonicIncreasingArrayIndices.empty()
                         ? -1
                         : monotonicIncreasingArrayIndices.top());
                long long value = arr[currentIndex];

                sum += leftSubArrayWidth * rightSubArrayWidth * value;
            }
            monotonicIncreasingArrayIndices.push(right);
        }
        arr.pop_back(); // Santient value;

        return sum % MOD;
    }
};