class Solution {
private:
    void createComb(vector<vector<int>>& answer, vector<int>& candidates,
                    vector<int>& comb, int sum, int target, int size,
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
            createComb(answer, candidates, comb, sum + candidates[i], target,
                       size, i + 1);
            comb.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int size = candidates.size();
        vector<vector<int>> answer;
        vector<int> comb;
        createComb(answer, candidates, comb, 0, target, size, 0);
        return answer;
    }
};