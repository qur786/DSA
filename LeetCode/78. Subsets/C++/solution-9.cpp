class Solution {
private:
    vector<int> comb;
    vector<vector<int>> answer;
    void getSubsets(vector<int>& nums, vector<bool>& visited, int size,
                    int index) {
        if (index == size) {
            answer.push_back(comb);
            return;
        }

        comb.push_back(nums[index]);
        getSubsets(nums, visited, size, index + 1);
        comb.pop_back();
        getSubsets(nums, visited, size, index + 1);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        getSubsets(nums, visited, nums.size(), 0);

        return answer;
    }
};