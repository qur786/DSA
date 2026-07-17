class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> numSet;
        numSet.reserve(1000);
        int maxPos = -1;

        for (int n : nums) {
            numSet.insert(n);
        }

        for (const int n : numSet) {
            if (numSet.count(-n))
                maxPos = max(maxPos, abs(n));
        }

        return maxPos;
    }
};