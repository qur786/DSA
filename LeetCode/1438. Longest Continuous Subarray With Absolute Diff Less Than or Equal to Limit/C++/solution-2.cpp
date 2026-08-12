class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int size = nums.size(), maxLen = 0, left = 0;
        deque<int> monotonicIncreasingDq, monotonicDecreasingDq;

        for (int right = 0; right < size; right++) {
            while (!monotonicIncreasingDq.empty() &&
                   (nums[right] < monotonicIncreasingDq.back()))
                monotonicIncreasingDq.pop_back();
            while (!monotonicDecreasingDq.empty() &&
                   (nums[right] > monotonicDecreasingDq.back()))
                monotonicDecreasingDq.pop_back();

            monotonicIncreasingDq.push_back(nums[right]);
            monotonicDecreasingDq.push_back(nums[right]);

            while (!monotonicDecreasingDq.empty() &&
                   !monotonicIncreasingDq.empty() &&
                   abs(monotonicIncreasingDq.front() -
                       monotonicDecreasingDq.front()) > limit) {
                if (monotonicDecreasingDq.front() == nums[left])
                    monotonicDecreasingDq.pop_front();
                if (monotonicIncreasingDq.front() == nums[left])
                    monotonicIncreasingDq.pop_front();
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};