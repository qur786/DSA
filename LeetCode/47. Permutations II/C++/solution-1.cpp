class Solution {
private:
    void genPerm(vector<vector<int>>& answer, vector<int>& nums,
                 vector<int>& perm, vector<bool>& visited, int size) {
        if (size == perm.size()) {
            answer.push_back(perm);
            return;
        }

        for (int i = 0; i < size; i++) {
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;
            if (!visited[i]) {
                perm.push_back(nums[i]);
                visited[i] = true;
                genPerm(answer, nums, perm, visited, size);
                perm.pop_back();
                visited[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        vector<int> perm;
        int size = nums.size();
        vector<bool> visited(size, false);

        genPerm(answer, nums, perm, visited, size);

        return answer;
    }
};