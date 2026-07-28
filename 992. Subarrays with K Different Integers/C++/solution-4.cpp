class Solution {
public:
    int subarraysWithAtMostK(vector<int>& nums, int k) {
        int left = 0, size = nums.size(), subArrayCount = 0;
        unordered_map<int, int> numCount;

        for (int right = 0; right < size; right++) {
            numCount[nums[right]]++;

            while (numCount.size() > k) {
                numCount[nums[left]]--;
                if (numCount[nums[left]] == 0)
                    numCount.erase(nums[left]);
                left++;
            }

            subArrayCount += right - left + 1;
        }

        return subArrayCount;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithAtMostK(nums, k) -
               subarraysWithAtMostK(nums, k - 1);
    }
};