class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff,
                                       int valueDiff) {
        set<int> numSet;
        int size = nums.size();
        int left = 0;

        for (int right = 0; right < size; right++) {
            if (right > indexDiff) {
                numSet.extract(nums[left]);
                left++;
            }

            int target = (nums[right] - valueDiff);
            auto It = numSet.lower_bound(target);
            if (It != numSet.end() && (*It) <= (nums[right] + valueDiff))
                return true;
            numSet.insert(nums[right]);
        }

        return false;
    }
};