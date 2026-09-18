class Solution {
private:
    void getSum(vector<vector<int>>& answer, vector<int>& candidates,
                vector<int>& sub, vector<bool>& visited, int sum, int target,
                int size, int index) {
        if (sum == target) {
            answer.push_back(sub);
            return;
        }

        for (int i = index; i < size; i++) {
            if (sum + candidates[i] > target)
                break;
            if (i > index && candidates[i] == candidates[i - 1] &&
                !visited[i - 1])
                continue;

            if (!visited[i]) {
                visited[i] = true;
                sub.push_back(candidates[i]);
                getSum(answer, candidates, sub, visited, sum + candidates[i], target,
                       size, i + 1);
                visited[i] = false;
                sub.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> sub;
        int size = candidates.size();
        vector<bool> visited(size, false);
        sort(candidates.begin(), candidates.end());
        getSum(answer, candidates, sub, visited, 0, target, size, 0);

        return answer;
    }
};