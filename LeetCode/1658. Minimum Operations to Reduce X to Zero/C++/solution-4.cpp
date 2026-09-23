class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        int size = nums.size();
        long long target = sum - x;
        long long currentSum = 0;

        int left = 0;
        int maxLen = INT_MIN;

        for (int right = 0; right < size; right++) {
            currentSum += nums[right];
            while (left <= right && currentSum > target) {
                currentSum -= nums[left];
                left++;
            }
            if (currentSum == target)
                maxLen = max(maxLen, right - left + 1);
        }

        return maxLen == INT_MIN ? -1 : size - maxLen;
    }
};