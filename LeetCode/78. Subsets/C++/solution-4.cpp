class Solution {
    void createSubsets(vector<vector<int>>& answer, vector<int>& currentSet,
                       vector<int>& nums, int index) {
        if (index == nums.size()) {
            answer.push_back(currentSet);
            return;
        }
        currentSet.push_back(nums[index]);
        createSubsets(answer, currentSet, nums, index + 1);
        currentSet.pop_back();
        createSubsets(answer, currentSet, nums, index + 1);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> currentSet;

        createSubsets(answer, currentSet, nums, 0);
        return answer;
    }
};