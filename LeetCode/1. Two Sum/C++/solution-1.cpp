class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numTargetMap;
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            if (numTargetMap.count(target - nums[i]))
                return {numTargetMap[target - nums[i]], i};
            numTargetMap[nums[i]] = i;
        }

        return {-1, -1};
    }
};