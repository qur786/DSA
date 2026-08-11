class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, size = nums.size(), maxLen = 0, ones = 0;

        for (int right = 0; right < size; right++) {
            if (nums[right] == 1)
                ones++;

            if ((right - left + 1) > (ones + k)) {
                if (nums[left] == 1)
                    ones--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};