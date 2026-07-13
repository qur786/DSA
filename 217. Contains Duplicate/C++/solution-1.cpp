class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numSet;

        for (int n : nums)
            if (numSet.count(n))
                return true;
            else
                numSet.insert(n);

        return false;
    }
};