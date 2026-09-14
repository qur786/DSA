class Solution {
private:
    void createSubSets(vector<vector<int>>& answer, vector<int>& currentSet,
                       vector<int>& nums, int index) {
        int size = nums.size();
        if (index == size) {
            answer.push_back(currentSet);
            return;
        }
        currentSet.push_back(nums[index]);
        createSubSets(answer, currentSet, nums, index + 1);
        while (index < (size - 1) && nums[index] == nums[index + 1])
            index++;
        currentSet.pop_back();
        createSubSets(answer, currentSet, nums, index + 1);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        vector<int> currentSet;
        createSubSets(answer, currentSet, nums, 0);

        return answer;
    }
};