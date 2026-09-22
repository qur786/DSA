class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> decr, incr;
        int left = 0;
        int maxLen = 0;
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            while (!incr.empty() && incr.back() > nums[i])
                incr.pop_back();
            while (!decr.empty() && decr.back() < nums[i])
                decr.pop_back();
            incr.push_back(nums[i]);
            decr.push_back(nums[i]);

            while (decr.front() - incr.front() > limit) {
                if (!incr.empty() && nums[left] == incr.front())
                    incr.pop_front();
                if (!decr.empty() && nums[left] == decr.front())
                    decr.pop_front();
                left++;
            }
            maxLen = max(maxLen, i - left + 1);
        }
        return maxLen;
    }
};