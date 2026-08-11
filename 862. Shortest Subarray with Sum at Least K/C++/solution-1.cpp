class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int size = nums.size(), minLen = INT_MAX;
        vector<int> prefixSum(size + 1, 0);
        deque<int> monotonicIncreasingQueue;

        for (int i = 0; i < size; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        for (int i = 0; i <= size; i++) {
            while (!monotonicIncreasingQueue.empty() &&
                   (prefixSum[i] -
                    prefixSum[monotonicIncreasingQueue.front()]) >= k) {
                minLen = min(minLen, i - monotonicIncreasingQueue.front());
                monotonicIncreasingQueue.pop_front();
            }
            while (!monotonicIncreasingQueue.empty() &&
                   prefixSum[monotonicIncreasingQueue.back()] > prefixSum[i]) {
                monotonicIncreasingQueue.pop_back();
            }
            monotonicIncreasingQueue.push_back(i);
        }

        return minLen == INT_MAX ? -1 : minLen;
    }
};