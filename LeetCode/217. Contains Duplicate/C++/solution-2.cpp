class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int size = nums.size();
        unordered_set<int> numSet;
        numSet.reserve(size);

        for (int n : nums)
            if (numSet.count(n))
                return true;
            else
                numSet.insert(n);

        return false;
    }
};