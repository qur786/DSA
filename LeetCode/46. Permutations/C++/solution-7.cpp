class Solution {
private:
    void solve(vector<int>& nums, vector<int>& comb, vector<bool>& visited,
               vector<vector<int>>& answer) {
        if (comb.size() == nums.size()) {
            answer.push_back(comb);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i])
                continue;
            visited[i] = true;
            comb.push_back(nums[i]);
            solve(nums, comb, visited, answer);
            comb.pop_back();
            visited[i] = false;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        int size = nums.size();
        vector<int> comb;
        comb.reserve(size);
        vector<bool> visited(size, false);
        vector<vector<int>> answer;
        solve(nums, comb, visited, answer);
        return answer;
    }
};