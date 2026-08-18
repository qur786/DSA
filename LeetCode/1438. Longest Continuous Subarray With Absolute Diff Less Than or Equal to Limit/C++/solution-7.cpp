class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> numSet;
        int left = 0;
        int size = nums.size();
        int maxLen = 0;

        for (int right = 0; right < size; right++) {
            numSet.insert(nums[right]);

            while ((*numSet.rbegin() - *numSet.begin()) > limit) {
                numSet.extract(nums[left]);
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};