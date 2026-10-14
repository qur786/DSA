class Solution {
private:
    vector<vector<int>> answer;
    vector<int> comb;
    void genPerm(vector<int>& nums, vector<bool>& visited, int size) {
        if (comb.size() == size) {
            answer.push_back(comb);
            return;
        }

        for (int i = 0; i < size; i++) {
            if (!visited[i]) {
                comb.push_back(nums[i]);
                visited[i] = true;
                genPerm(nums, visited, size);
                visited[i] = false;
                comb.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        genPerm(nums, visited, nums.size());

        return answer;
    }
};