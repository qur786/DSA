class Solution {
private:
    void createSubset(vector<vector<int>>& answer, vector<int>& nums,
                      vector<int>& sub, int index) {
        if (index == nums.size()) {
            answer.push_back(sub);
            return;
        }

        sub.push_back(nums[index]);
        createSubset(answer, nums, sub, index + 1);
        sub.pop_back();
        createSubset(answer, nums, sub, index + 1);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> sub;
        createSubset(answer, nums, sub, 0);
        return answer;
    }
};