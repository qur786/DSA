class Solution {
private:
    void createPerm(vector<vector<int>>& answer, vector<int>& nums,
                    vector<int>& perm, vector<bool>& visited, int size) {
        if (perm.size() == size) {
            answer.push_back(perm);
            return;
        }

        for (int i = 0; i < size; i++) {
            if (!visited[i]) {
                visited[i] = true;
                perm.push_back(nums[i]);
                createPerm(answer, nums, perm, visited, size);
                visited[i] = false;
                perm.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> perm;
        int size = nums.size();
        vector<bool> visited(size, false);
        createPerm(answer, nums, perm, visited, size);
        return answer;
    }
};