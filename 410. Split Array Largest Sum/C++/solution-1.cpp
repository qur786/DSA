class Solution {
public:
    bool canSplitArray(vector<int>& nums, int subArrayNum, int sum) {
        long long totalSubArray = 1, currentSum = 0;

        for (int num : nums) {
            if (((long long)currentSum + num) > sum) {
                totalSubArray += 1;
                currentSum = num;
            } else {
                currentSum += num;
            }
        }

        return totalSubArray <= subArrayNum;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int result = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canSplitArray(nums, k, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }
};