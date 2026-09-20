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
            if (sum + candidates[i] > target)
                continue;
            comb.push_back(candidates[i]);
            createComb(answer, candidates, comb, sum + candidates[i], target,
                       size, i);
            comb.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> comb;
        int size = candidates.size();
        createComb(answer, candidates, comb, 0, target, size, 0);

        return answer;
    }
};