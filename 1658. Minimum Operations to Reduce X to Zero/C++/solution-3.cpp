class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int size = nums.size(), left = 0, maxLen = INT_MIN;
        long long total = accumulate(nums.begin(), nums.end(), 0);
        long long target = total - x, sum = 0;
        if (target < 0)
            return -1;
        else if (target == 0)
            return size;

        for (int right = 0; right < size; right++) {
            sum += nums[right];

            while (sum > target) {
                sum -= nums[left];
                left++;
            }

            if (sum == target)
                maxLen = max(maxLen, right - left + 1);
        }

        return maxLen == INT_MIN ? -1 : (size - maxLen);
    }
};