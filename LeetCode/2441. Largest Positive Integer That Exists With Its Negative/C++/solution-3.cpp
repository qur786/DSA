class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxValue = -1;

        for (const auto& n : numSet)
            if (n > 0 && numSet.count(-n))
                maxValue = max(maxValue, n);

        return maxValue;
    }
};