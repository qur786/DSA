class Solution {
private:
    void createPerm(vector<vector<int>>& answer, vector<int>& nums,
                    vector<int>& comb, vector<bool>& visited) {
        int size = nums.size();
        if (comb.size() == size) {
            answer.push_back(comb);
            return;
        }

        for (int i = 0; i < size; i++) {
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])
                continue;
            if (!visited[i]) {
                visited[i] = true;
                comb.push_back(nums[i]);
                createPerm(answer, nums, comb, visited);
                visited[i] = false;
                comb.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        vector<int> comb;
        int size = nums.size();
        vector<bool> visited(size, false);
        createPerm(answer, nums, comb, visited);

        return answer;
    }
};