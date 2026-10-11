class Solution {
private:
    vector<vector<int>> answer;
    vector<int> comb;
    void getSubsets(vector<int>& nums, int size, int index) {
        if (index == size) {
            answer.push_back(comb);
            return;
        }

        comb.push_back(nums[index]);
        getSubsets(nums, size, index + 1);
        while (index < size - 1 && nums[index] == nums[index + 1])
            index++;
        comb.pop_back();
        getSubsets(nums, size, index + 1);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        getSubsets(nums, size, 0);

        return answer;
    }
};