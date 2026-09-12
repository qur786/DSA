class Solution {
private:
    void createSubSet(vector<vector<int>>& result, vector<int>& currentVec,
                      vector<int>& nums, int index) {
        if (index == nums.size()) {
            result.push_back(currentVec);
            return;
        }
        currentVec.push_back(nums[index]);
        createSubSet(result, currentVec, nums, index + 1);
        currentVec.pop_back();
        createSubSet(result, currentVec, nums, index + 1);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> currentVec;
        createSubSet(answer, currentVec, nums, 0);

        return answer;
    }
};