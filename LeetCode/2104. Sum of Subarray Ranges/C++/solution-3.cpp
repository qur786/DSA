class Solution {
public:
    long long getSumOfMaximums(vector<int>& nums) {
        nums.push_back(INT_MAX); // Santient value;
        int size = nums.size();
        stack<int> monotonicDecreasingStack;
        long long sum = 0;

        for (int i = 0; i < size; i++) {
            while (!monotonicDecreasingStack.empty() &&
                   nums[monotonicDecreasingStack.top()] < nums[i]) {
                int currentIndex = monotonicDecreasingStack.top();
                monotonicDecreasingStack.pop();
                int right = i - currentIndex;
                int left = monotonicDecreasingStack.empty()
                               ? currentIndex + 1
                               : currentIndex - monotonicDecreasingStack.top();

                sum += (long long)right * left * nums[currentIndex];
            }
            monotonicDecreasingStack.push(i);
        }

        nums.pop_back();

        return sum;
    }
    long long getSumOfMinimums(vector<int>& nums) {
        nums.push_back(INT_MIN); // Santient value;
        int size = nums.size();
        stack<int> monotonicIncreasingStack;
        long long sum = 0;

        for (int i = 0; i < size; i++) {
            while (!monotonicIncreasingStack.empty() &&
                   nums[monotonicIncreasingStack.top()] > nums[i]) {
                int currentIndex = monotonicIncreasingStack.top();
                monotonicIncreasingStack.pop();
                int right = i - currentIndex;
                int left = monotonicIncreasingStack.empty()
                               ? currentIndex + 1
                               : currentIndex - monotonicIncreasingStack.top();

                sum += (long long)right * left * nums[currentIndex];
            }
            monotonicIncreasingStack.push(i);
        }

        nums.pop_back();

        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        return getSumOfMaximums(nums) - getSumOfMinimums(nums);
    }
};