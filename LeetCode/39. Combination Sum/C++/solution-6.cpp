class Solution {
private:
    void solve(vector<vector<int>>& answer, vector<int>& candidates,
               vector<int>& comb, int sum, int size, int index, int target) {
        if (sum >= target) {
            if (sum == target)
                answer.push_back(comb);
            return;
        }

        for (int i = index; i < size; i++) {
            comb.push_back(candidates[i]);
            solve(answer, candidates, comb, sum + candidates[i], size, i,
                  target);
            comb.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        int size = candidates.size();
        vector<vector<int>> answer;
        solve(answer, candidates, comb, 0, size, 0, target);

        return answer;
    }
};