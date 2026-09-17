class Solution {
private:
    void createCombSum(vector<vector<int>>& answer, vector<int>& candidates,
                       vector<int>& comb, int target, int sum, int size,
                       int index) {
        if (sum == target) {
            answer.push_back(comb);
            return;
        }

        for (int i = index; i < size; i++) {
            if (i > index && candidates[i] == candidates[i - 1])
                continue;
            if (sum + candidates[i] > target)
                break;

            comb.push_back(candidates[i]);
            createCombSum(answer, candidates, comb, target,
                          sum + candidates[i], size, i + 1);
            comb.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> answer;
        vector<int> comb;
        int size = candidates.size();
        createCombSum(answer, candidates, comb, target, 0, size, 0);

        return answer;
    }
};