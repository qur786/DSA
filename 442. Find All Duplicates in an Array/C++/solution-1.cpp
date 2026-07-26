class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int size = nums.size();
        vector<int> result;
        result.reserve(size);

        for (int i = 0; i < size; i++) {
            int absN = abs(nums[i]);
            if (nums[absN - 1] < 0)
                result.push_back(absN);
            nums[absN - 1] = -nums[absN - 1];
        }

        return result;
    }
};