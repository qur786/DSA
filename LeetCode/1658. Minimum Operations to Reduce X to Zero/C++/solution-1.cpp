class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long total = accumulate(nums.begin(), nums.end(), 0);
        long long target = total - x;
        long long size = nums.size(), left = 0, maxLen = 0, sum = 0;

        if (target == 0)
            return size;

        for (int right = 0; right < size; right++) {
            sum += nums[right];
            while (left <= right && sum > target) {
                sum -= nums[left];
                left += 1;
            }
            if (sum == target)
                maxLen = max(maxLen, right - left + 1);
        }

        return maxLen == 0 ? -1 : size - maxLen;
    }
};