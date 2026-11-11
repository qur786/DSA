class Solution {
private:
    void solve(vector<vector<int>>& answer, vector<int>& comb,
               vector<int>& nums, vector<bool>& visited, int size) {
        if (comb.size() == size) {
            answer.push_back(comb);
            return;
        }

        for (int i = 0; i < size; i++) {
            if (visited[i])
                continue;
            visited[i] = true;
            comb.push_back(nums[i]);
            solve(answer, comb, nums, visited, size);
            visited[i] = false;
            comb.pop_back();
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> answer;
        vector<int> comb;
        comb.reserve(size);
        vector<bool> visited(size, false);
        solve(answer, comb, nums, visited, size);
        return answer;
    }
};