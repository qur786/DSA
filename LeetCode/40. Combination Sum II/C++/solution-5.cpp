class Solution {
private:
    vector<vector<int>> answer;
    vector<int> comb;
    void genComb(vector<int>& candidates, int target, int sum, int size,
                 int index, vector<bool>& visited) {
        if (sum == target) {
            answer.push_back(comb);
            return;
        }

        for (int i = index; i < size; i++) {
            if (visited[i])
                continue;
            if (i > 0 && candidates[i] == candidates[i - 1] && !visited[i - 1])
                continue;
            if (sum + candidates[i] > target)
                return;
            visited[i] = true;
            comb.push_back(candidates[i]);
            genComb(candidates, target, sum + candidates[i], size, i + 1,
                    visited);
            comb.pop_back();
            visited[i] = false;
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<bool> visited(candidates.size(), false);
        genComb(candidates, target, 0, candidates.size(), 0, visited);

        return answer;
    }
};