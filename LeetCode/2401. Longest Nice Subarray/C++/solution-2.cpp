class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int used_bits = 0, left = 0, maxLen = 0, size = nums.size();

        for (int right = 0; right < size; right++) {
            while ((used_bits & nums[right]) != 0) {
                used_bits ^= nums[left];
                left++;
            }
            used_bits |= nums[right];
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};