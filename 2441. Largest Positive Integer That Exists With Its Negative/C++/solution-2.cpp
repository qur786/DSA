class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxPos = -1;

        for (const int n : numSet) {
            if (n < 0)
                continue;
            if (numSet.count(-n))
                maxPos = max(maxPos, n);
        }

        return maxPos;
    }
};