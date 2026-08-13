class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            while (nums[i] > 0 && nums[i] <= size &&
                   nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        }

        vector<int> result;

        for (int i = 0; i < size; i++)
            if (nums[i] != (i + 1))
                result.push_back(i + 1);

        return result;
    }
};