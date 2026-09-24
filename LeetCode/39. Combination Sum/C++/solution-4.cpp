class Solution {
private:
    void createComb(vector<vector<int>>& answer, vector<int>& candidates,
                    vector<int>& comb, int target, int sum, int index,
                    int size) {
        if (sum == target) {
            answer.push_back(comb);
            return;
        }

        for (int i = index; i < size; i++) {
            if (sum + candidates[i] > target)
                continue;
            comb.push_back(candidates[i]);
            createComb(answer, candidates, comb, target, sum + candidates[i], i,
                       size);
            comb.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> comb;
        int size = candidates.size();
        createComb(answer, candidates, comb, target, 0, 0, size);
        return answer;
    }
};