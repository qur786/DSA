class Solution {
private:
    void solve(vector<vector<int>>& answer, vector<int>& candidates,
               vector<int>& comb, vector<bool>& visited, int sum, int index,
               int size, int target) {
        if (sum >= target) {
            if (sum == target)
                answer.push_back(comb);
            return;
        }

        for (int i = index; i < size; i++) {
            if (visited[i])
                continue;
            if (i > index && candidates[i] == candidates[i - 1] &&
                !visited[i - 1])
                continue;
            comb.push_back(candidates[i]);
            visited[i] = true;
            solve(answer, candidates, comb, visited, sum + candidates[i], i + 1,
                  size, target);
            comb.pop_back();
            visited[i] = false;
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), greater<int>());
        int size = candidates.size();
        vector<vector<int>> answer;
        vector<int> comb;
        vector<bool> visited(size, false);

        solve(answer, candidates, comb, visited, 0, 0, size, target);

        return answer;
    }
};