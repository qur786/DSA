class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int size = nums.size();
        vector<long long> prefixSum(size + 1, 0);
        deque<int> dq;
        int minLen = INT_MAX;

        for (int i = 1; i <= size; i++)
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];

        for (int i = 0; i <= size; i++) {
            while (!dq.empty() && (prefixSum[i] - prefixSum[dq.front()]) >= k) {
                minLen = min(minLen, i - dq.front());
                dq.pop_front();
            }

            while (!dq.empty() && (prefixSum[i] <= prefixSum[dq.back()]))
                dq.pop_back();

            dq.push_back(i);
        }
        return minLen == INT_MAX ? -1 : minLen;
    }
};