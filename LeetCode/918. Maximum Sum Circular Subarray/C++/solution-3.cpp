class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        long long minSum = nums[0], maxSum = nums[0], currMinSum = nums[0],
                  currMaxSum = nums[0];
        int size = nums.size();
        long long total = accumulate(nums.begin(), nums.end(), 0LL);

        for (int i = 1; i < size; i++) {
            currMinSum =
                min((long long)nums[i], (long long)nums[i] + currMinSum);
            currMaxSum =
                max((long long)nums[i], (long long)nums[i] + currMaxSum);
            minSum = min(minSum, currMinSum);
            maxSum = max(maxSum, currMaxSum);
        }

        return minSum == total ? maxSum : max(maxSum, total - minSum);
    }
};