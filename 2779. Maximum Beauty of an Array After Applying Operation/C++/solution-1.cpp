class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int size = nums.size(), maxLen = 0;

        for (int i = 0; i < size; i++) {
            auto ub = upper_bound(nums.begin(), nums.end(), nums[i] + 2 * k);
            int len = distance(nums.begin() + i, ub);
            maxLen = max(len, maxLen);
        }

        return maxLen;
    }
};