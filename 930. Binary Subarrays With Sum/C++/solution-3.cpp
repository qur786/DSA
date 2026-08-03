class Solution {
public:
    int numSubarraysWithAtMostSum(vector<int>& nums, int goal) {
        int sum = 0, size = nums.size(), subArrayCount = 0, left = 0;

        for (int right = 0; right < size; right++) {
            sum += nums[right];
            while (sum > goal && left <= right) {
                sum -= nums[left];
                left++;
            }
            subArrayCount += right - left + 1;
        }

        return subArrayCount;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numSubarraysWithAtMostSum(nums, goal) -
               numSubarraysWithAtMostSum(nums, goal - 1);
    }
};