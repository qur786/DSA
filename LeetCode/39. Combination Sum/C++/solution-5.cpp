class Solution {
private:
    vector<vector<int>> answer;
    vector<int> comb;
    void getComb(vector<int>& candidates, int target, int size, int index,
                 int sum) {
        if (sum == target) {
            answer.push_back(comb);
            return;
        }

        for (int i = index; i < size; i++) {
            if (sum + candidates[i] > target)
                return;
            comb.push_back(candidates[i]);
            getComb(candidates, target, size, i, sum + candidates[i]);
            comb.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        getComb(candidates, target, candidates.size(), 0, 0);

        return answer;
    }
};