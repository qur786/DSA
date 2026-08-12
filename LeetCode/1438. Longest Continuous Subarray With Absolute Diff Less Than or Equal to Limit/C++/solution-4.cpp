class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> incr, decr;
        int size = nums.size(), maxLen = 0, left = 0;

        for (int right = 0; right < size; right++) {
            while (!incr.empty() && nums[right] < incr.back())
                incr.pop_back();
            while (!decr.empty() && nums[right] > decr.back())
                decr.pop_back();

            incr.push_back(nums[right]);
            decr.push_back(nums[right]);

            while (!incr.empty() && !decr.empty() &&
                   (decr.front() - incr.front()) > limit) {
                if (nums[left] == incr.front())
                    incr.pop_front();
                if (nums[left] == decr.front())
                    decr.pop_front();
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};