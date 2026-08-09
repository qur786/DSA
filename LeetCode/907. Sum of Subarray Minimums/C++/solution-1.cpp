class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> monotonicIncreasingStack;
        int size = arr.size(), MOD = 1e9 + 7;
        arr.push_back(INT_MIN); // Santient value
        long long sum = 0;

        for (int right = 0; right <= size; right++) {
            while (!monotonicIncreasingStack.empty() &&
                   arr[monotonicIncreasingStack.top()] > arr[right]) {
                int currentIndex = monotonicIncreasingStack.top();
                monotonicIncreasingStack.pop();
                int left = monotonicIncreasingStack.empty()
                               ? -1
                               : monotonicIncreasingStack.top();
                int leftSubArrayCountWithCurrentElementAsMinimum =
                    currentIndex - left;
                int rightSubArrayCountWithCurrentElementAsMinimum =
                    right - currentIndex;
                int subArrayCountWithCurrentElementAsMinimum =
                    leftSubArrayCountWithCurrentElementAsMinimum *
                    rightSubArrayCountWithCurrentElementAsMinimum;
                sum += (long long)arr[currentIndex] *
                       subArrayCountWithCurrentElementAsMinimum;
            }
            monotonicIncreasingStack.push(right);
        }

        arr.pop_back();

        return sum % MOD;
    }
};