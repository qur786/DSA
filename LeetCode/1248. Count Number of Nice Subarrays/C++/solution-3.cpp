class Solution {
public:
    int numberOfAtMostKOddSubarrays(vector<int>& nums, int k) {
        int size = nums.size(), left = 0, oddCount = 0,
            subArrayWithAtMostKOdd = 0;

        for (int right = 0; right < size; right++) {
            oddCount += nums[right] % 2;
            while (oddCount > k) {
                oddCount -= nums[left] % 2;
                left++;
            }
            subArrayWithAtMostKOdd += right - left + 1;
        }

        return subArrayWithAtMostKOdd;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return numberOfAtMostKOddSubarrays(nums, k) -
               numberOfAtMostKOddSubarrays(nums, k - 1);
    }
};