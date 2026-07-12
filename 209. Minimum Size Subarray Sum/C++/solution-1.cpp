class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size(), minLen = INT_MAX, sum = 0, left = 0;

        for (int right = 0; right < size; right++) {
            sum += nums[right];

            while (sum >= target) {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};