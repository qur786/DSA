class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        long long maxSum = INT_MIN;
        int size = nums.size();
        int newSize = 2 * size;
        nums.insert(nums.end(), nums.begin(), nums.end());
        vector<long long> prefixSum(newSize + 1, 0);
        deque<int> dq;

        for (int i = 1; i <= newSize; i++)
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];

        for (int i = 0; i <= newSize; i++) {
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