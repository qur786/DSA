class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int size = nums.size();
        deque<int> incr, decr;
        int left = 0;
        int maxLen = 0;

        for (int i = 0; i < size; i++) {
            while (!incr.empty() && nums[i] < incr.back())
                incr.pop_back();
            while (!decr.empty() && nums[i] > decr.back())
                decr.pop_back();
            incr.push_back(nums[i]);
            decr.push_back(nums[i]);
            while (!incr.empty() && !decr.empty() &&
                   (decr.front() - incr.front()) > limit) {
                if (incr.front() == nums[left])
                    incr.pop_front();
                if (decr.front() == nums[left])
                    decr.pop_front();
                left++;
            }

            if (!incr.empty() && !decr.empty()) {
                maxLen = max(maxLen, i - left + 1);
            }
        }

        return maxLen;
    }
};