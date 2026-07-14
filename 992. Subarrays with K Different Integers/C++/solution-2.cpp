class Solution {
public:
    int subarraysWithAtMostKDistinct(const vector<int>& nums, int k) {
        int left = 0, size = nums.size(), count = 0;
        unordered_map<int, int> numMap;

        for (int i = 0; i < size; i++) {
            numMap[nums[i]]++;
            while (numMap.size() > k) {
                numMap[nums[left]]--;
                if (numMap[nums[left]] == 0)
                    numMap.erase(nums[left]);
                left++;
            }
            count += i - left;
        }

        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithAtMostKDistinct(nums, k) -
               subarraysWithAtMostKDistinct(nums, k - 1);
    }
};