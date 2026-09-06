class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int size = nums.size();
        int size2 = 2 * size;
        nums.insert(nums.end(), nums.begin(), nums.end());
        vector<long long> prefixSum(size2 + 1, 0LL);

        for (int i = 1; i <= size2; i++)
            prefixSum[i] = prefixSum[i - 1] + (long long)nums[i - 1];

        deque<int> dq;
        long long maxSum = LLONG_MIN;

        for (int i = 0; i <= size2; i++) {
            while (!dq.empty() && (i - dq.front()) > size)
                dq.pop_front();
            if (!dq.empty())
                maxSum = max(maxSum, prefixSum[i] - prefixSum[dq.front()]);
            while (!dq.empty() && (prefixSum[i] <= prefixSum[dq.back()]))
                dq.pop_back();
            dq.push_back(i);
        }

        return maxSum;
    }
};