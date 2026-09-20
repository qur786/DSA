class Solution {
private:
    void createPerm(vector<vector<int>>& answer, vector<int>& nums,
                    vector<int>& sub, vector<bool>& visited, int size) {
        if (size == sub.size()) {
            answer.push_back(sub);
            return;
        }

        for (int i = 0; i < size; i++) {
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])
                continue;
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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        vector<int> sub;
        int size = nums.size();
        vector<bool> visited(size, false);
        createPerm(answer, nums, sub, visited, size);

        return answer;
    }
};