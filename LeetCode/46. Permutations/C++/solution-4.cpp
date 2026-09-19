class Solution {
private:
    void createPerm(vector<vector<int>>& answer, vector<int>& nums,
                    vector<int>& sub, vector<bool>& visited, int size) {
        if (sub.size() == size) {
            answer.push_back(sub);
            return;
        }

        for (int i = 0; i < size; i++) {
            if (!visited[i]) {
                visited[i] = true;
                sub.push_back(nums[i]);
                createPerm(answer, nums, sub, visited, size);
                visited[i] = false;
                sub.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> sub;
        int size = nums.size();
        vector<bool> visited(size, false);
        createPerm(answer, nums, sub, visited, size);
        return answer;
    }
};