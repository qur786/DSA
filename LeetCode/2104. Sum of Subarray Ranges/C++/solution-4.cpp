class Solution {
public:
    long long subArrayMaximumSum(vector<int>& nums) {
        nums.push_back(INT_MAX); // Santient value
        int size = nums.size();
        stack<int> monotonicDecreasingNumIndces;
        long long sum = 0;

        for (int right = 0; right < size; right++) {
            while (!monotonicDecreasingNumIndces.empty() &&
                   nums[monotonicDecreasingNumIndces.top()] < nums[right]) {
                int currentIndex = monotonicDecreasingNumIndces.top();
                monotonicDecreasingNumIndces.pop();
                int left = monotonicDecreasingNumIndces.empty()
                               ? -1
                               : monotonicDecreasingNumIndces.top();

                long long leftPart = currentIndex - left;
                long long rightPart = right - currentIndex;
                long long value = nums[currentIndex];
                sum += leftPart * rightPart * value;
            }
            monotonicDecreasingNumIndces.push(right);
        }
        nums.pop_back();

        return sum;
    }
    long long subArrayMinimumSum(vector<int>& nums) {
        nums.push_back(INT_MIN); // Santient value
        int size = nums.size();
        stack<int> monotonicIncreasingNumIndces;
        long long sum = 0;

        for (int right = 0; right < size; right++) {
            while (!monotonicIncreasingNumIndces.empty() &&
                   nums[monotonicIncreasingNumIndces.top()] > nums[right]) {
                int currentIndex = monotonicIncreasingNumIndces.top();
                monotonicIncreasingNumIndces.pop();
                int left = monotonicIncreasingNumIndces.empty()
                               ? -1
                               : monotonicIncreasingNumIndces.top();

                long long leftPart = currentIndex - left;
                long long rightPart = right - currentIndex;
                long long value = nums[currentIndex];
                sum += leftPart * rightPart * value;
            }
            monotonicIncreasingNumIndces.push(right);
        }
        nums.pop_back();

        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        return subArrayMaximumSum(nums) - subArrayMinimumSum(nums);
    }
};