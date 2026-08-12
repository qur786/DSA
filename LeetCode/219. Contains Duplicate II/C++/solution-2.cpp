class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> numMap;
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            if (numMap.count(nums[i]) && abs(numMap[nums[i]] - i) <= k)
                return true;
            numMap[nums[i]] = i;
        }

        return false;
    }
};