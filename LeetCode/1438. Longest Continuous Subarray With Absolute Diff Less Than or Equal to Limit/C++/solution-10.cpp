class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> numSet;
        int size = nums.size();
        int left = 0;
        int maxLen = 0;

        for (int i = 0; i < size; i++) {
            numSet.insert(nums[i]);
            while (*numSet.rbegin() - *numSet.begin() > limit) {
                numSet.extract(nums[left]);
                left++;
            }
            maxLen = max(maxLen, i - left + 1);
        }

        return maxLen;
    }
};