class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> numSet;
        int size = nums.size(), maxLen = 0, left = 0;

        for (int right = 0; right < size; right++) {
            numSet.insert(nums[right]);

            while ((*numSet.rbegin() - *numSet.begin()) > limit)
                numSet.extract(nums[left++]);

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};