class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int left = 0, size = nums.size();
        long long sum = 0, maxSum = 0;
        unordered_map<int, int> numCount;

        for (int right = 0; right < size; right++) {
            numCount[nums[right]]++;
            sum += nums[right];

            if (right - left + 1 > k) {
                numCount[nums[left]]--;
                sum -= nums[left];
                if (numCount[nums[left]] == 0)
                    numCount.erase(nums[left]);
                left++;
            }

            if (right - left + 1 == k && numCount.size() >= m)
                maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};