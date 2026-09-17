class Solution {
private:
    void createComb(vector<vector<int>>& answer, vector<int>& candidates,
                    vector<int>& comb, int size, int sum, int target,
                    int index) {
        if (sum == target) {
            answer.push_back(comb);
            return;
        }

        for (int i = index; i < size; i++) {
            if (sum + candidates[i] > target)
                continue;
            comb.push_back(candidates[i]);
            createComb(answer, candidates, comb, size, sum + candidates[i],
                       target, i);
            comb.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> answer;
        vector<int> comb;
        int size = candidates.size();
        createComb(answer, candidates, comb, size, 0, target, 0);

        return answer;
    }
};