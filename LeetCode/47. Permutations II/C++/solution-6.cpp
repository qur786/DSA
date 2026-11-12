class Solution {
private:
    void solve(vector<vector<int>>& answer, vector<int>& nums,
               vector<int>& comb, vector<bool>& visited, int size) {
        if (comb.size() == size) {
            answer.push_back(comb);
            return;
        }

        for (int i = 0; i < size; i++) {
            if (visited[i])
                continue;
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])
                continue;
            comb.push_back(nums[i]);
            visited[i] = true;
            solve(answer, nums, comb, visited, size);
            comb.pop_back();
            visited[i] = false;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<vector<int>> answer;
        vector<int> comb;
        comb.reserve(size);
        vector<bool> visited(size, false);
        solve(answer, nums, comb, visited, size);
        return answer;
    }
};