class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left = 0, size = nums.size();
        multiset<int> values;
        int maxLen = 0;

        for (int right = 0; right < size; right++) {
            values.insert(nums[right]);

            while (left <= right &&
                   abs(*values.begin() - *values.rbegin()) > limit) {
                values.extract(nums[left]);
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};