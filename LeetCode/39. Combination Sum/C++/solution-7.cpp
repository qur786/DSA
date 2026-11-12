class Solution {
private:
    void solve(vector<vector<int>>& answer, vector<int>& nums,
               vector<int>& comb, int sum, int target, int size, int index) {
        if (sum >= target) {
            if (sum == target)
                answer.push_back(comb);
            return;
        }

        for (int i = index; i < size; i++) {
            comb.push_back(nums[i]);
            solve(answer, nums, comb, sum + nums[i], target, size, i);
            comb.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> comb;
        int size = candidates.size();
        solve(answer, candidates, comb, 0, target, size, 0);
        return answer;
    }
};