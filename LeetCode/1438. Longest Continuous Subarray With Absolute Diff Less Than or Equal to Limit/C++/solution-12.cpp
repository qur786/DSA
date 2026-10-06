class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> m;
        int size = nums.size();
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < size; right++) {
            m.insert(nums[right]);

            while (!m.empty() && (*prev(m.end()) - *m.begin()) > limit) {
                m.extract(nums[left]);
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};