class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long left = 0, maxSum = 0, size = nums.size(), sum = 0;
        unordered_map<int, int> numMap;

        for (int right = 0; right < size; right++) {
            while (numMap.count(nums[right]) && numMap[nums[right]] >= left) {
                sum -= nums[left];
                left++;
            }
            while ((right - left + 1) > k) {
                sum -= nums[left];
                left++;
            }
            sum += nums[right];
            numMap[nums[right]] = right;

            if ((right - left + 1) == k)
                maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};