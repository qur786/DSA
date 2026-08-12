class Solution {
public:
    int subarraysWithKAtMost(vector<int>& nums, int k) {
        int left = 0, size = nums.size(), count = 0;
        unordered_map<int, int> numMap;

        for (int right = 0; right < size; right++) {
            numMap[nums[right]]++;
            while (numMap.size() > k) {
                numMap[nums[left]]--;
                if (numMap[nums[left]] == 0)
                    numMap.erase(nums[left]);
                left++;
            }
            count += right - left + 1;
        }

        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithKAtMost(nums, k) -
               subarraysWithKAtMost(nums, k - 1);
    }
};