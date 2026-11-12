class Solution {
private:
    void solve(vector<vector<int>>& answer, vector<int>& nums,
               vector<int>& comb, vector<bool>& visited, int sum, int target,
               int size, int index) {
        if (sum >= target) {
            if (sum == target)
                answer.push_back(comb);
            return;
        }

        for (int i = index; i < size; i++) {
            if (visited[i])
                continue;
            if (i > index && nums[i] == nums[i - 1] && !visited[i - 1])
                continue;
            visited[i] = true;
            comb.push_back(nums[i]);
            solve(answer, nums, comb, visited, sum + nums[i], target, size,
                  i + 1);
            comb.pop_back();
            visited[i] = false;
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        if (candidates[0] > target)
            return {};
        vector<vector<int>> answer;
        vector<int> comb;
        int size = candidates.size();
        vector<bool> visited(size, false);
        solve(answer, candidates, comb, visited, 0, target, size, 0);

        return answer;
    }
};