class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, size = nums.size(), ones = 0, maxLen = 0;

        for (int right = 0; right < size; right++) {
            ones += nums[right];

            while ((right - left + 1) > (ones + 1)) {
                ones -= nums[left];
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen == 0 ? 0 : maxLen - 1;
    }
};