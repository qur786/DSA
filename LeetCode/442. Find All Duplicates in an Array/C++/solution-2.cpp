class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int size = nums.size();
        vector<int> result;
        for (int i = 0; i < size; i++) {
            int value = abs(nums[i]);
            if (nums[value - 1] < 0)
                result.push_back(value);
            else
                nums[value - 1] = -nums[value - 1];
        }

        return result;
    }
};