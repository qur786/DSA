class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numIndices;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (numIndices.count(target - nums[i]))
                return {numIndices[target - nums[i]], i};

            numIndices[nums[i]] = i;
        }

        return {-1, -1};
    }
};