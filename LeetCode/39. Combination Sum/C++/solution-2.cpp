class Solution {
private:
    void getSum(vector<vector<int>>& answer, vector<int>& candidates,
                vector<int>& sub, int sum, int target, int size, int index) {
        if (sum == target) {
            answer.push_back(sub);
            return;
        }

        for (int i = index; i < size; i++) {
            if (sum + candidates[i] > target)
                break;
            sub.push_back(candidates[i]);
            getSum(answer, candidates, sub, sum + candidates[i], target, size,
                   i);
            sub.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> answer;
        vector<int> sub;
        int size = candidates.size();

        getSum(answer, candidates, sub, 0, target, size, 0);
        return answer;
    }
};