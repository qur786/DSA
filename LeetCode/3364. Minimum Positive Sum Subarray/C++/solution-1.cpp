class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int size = nums.size();
        vector<long long> prefixSum(size + 1, 0);
        long long minSum = LLONG_MAX;

        for (int i = 1; i <= size; i++)
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];

        for (int i = l; i <= r; i++) {
            int init = 0;
            int end = i;
            while (end <= size) {
                long long pre = prefixSum[end] - prefixSum[init];
                minSum = pre <= 0 ? minSum : min(minSum, pre);
                end++;
                init++;
            }
        }

        return minSum == LLONG_MAX ? -1 : minSum;
    }
};