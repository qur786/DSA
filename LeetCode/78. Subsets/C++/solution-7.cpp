class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer(1);
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int size = answer.size();
            for (int j = 0; j < size; j++) {
                answer.push_back(answer[j]);
                answer.back().push_back(nums[i]);
            }
        }

        return answer;
    }
};