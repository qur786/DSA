class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int size = nums.size(), left = 0, maxLen = 1, sum = 0, x = 0;

        // If A & B = 0, so A ^ B = A + B
        for (int right = 0; right < size; right++) {
            sum += nums[right];
            x ^= nums[right];

            if (sum == x)
                maxLen = max(maxLen, right - left + 1);
            else {
                while (left <= right && sum != x) {
                    sum -= nums[left];
                    x ^= nums[left];
                    left++;
                }
            }
        }

        return maxLen;
    }
};