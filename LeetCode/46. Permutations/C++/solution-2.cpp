class Solution {
private:
    void producePerm(vector<vector<int>>& answer, vector<int>& nums,
                     vector<int>& pattern, vector<bool>& visited) {
        if (pattern.size() == nums.size()) {
            answer.push_back(pattern);
            return;
        }
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (!visited[i]) {
                visited[i] = true;
                pattern.push_back(nums[i]);
                producePerm(answer, nums, pattern, visited);
                visited[i] = false;
                pattern.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        int size = nums.size();
        vector<bool> visited(size, false);
        vector<int> pattern;
        producePerm(answer, nums, pattern, visited);
        return answer;
    }
};