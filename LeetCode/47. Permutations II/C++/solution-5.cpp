class Solution {
private:
    void solve(vector<int>& nums, vector<int>& comb,
               vector<vector<int>>& answer, vector<bool>& visited, int size) {
        if (comb.size() == size) {
            answer.push_back(comb);
            return;
        }

        for (int i = 0; i < size; i++) {
            if (visited[i])
                continue;
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])
                continue;
            visited[i] = true;
            comb.push_back(nums[i]);
            solve(nums, comb, answer, visited, size);
            comb.pop_back();
            visited[i] = false;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<int> comb;
        vector<vector<int>> answer;
        vector<bool> visited(size, false);
        solve(nums, comb, answer, visited, size);

        return answer;
    }
};