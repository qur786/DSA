class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> numsMap;
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            if (numsMap.count(nums[i]) && abs(numsMap[nums[i]] - i) <= k)
                return true;
            numsMap[nums[i]] = i;
        }

        return false;
    }
};