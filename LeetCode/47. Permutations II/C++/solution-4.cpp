class Solution {
private:
    vector<vector<int>> answer;
    vector<int> comb;
    void getPerm(vector<int>& nums, vector<bool>& visited, int size) {
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
            getPerm(nums, visited, size);
            comb.pop_back();
            visited[i] = false;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int size = nums.size();
        vector<bool> visited(size, false);
        sort(nums.begin(), nums.end());
        getPerm(nums, visited, size);

        return answer;
    }
};