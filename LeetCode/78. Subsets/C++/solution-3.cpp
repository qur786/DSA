class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int p = pow(2, n);
        vector<vector<int>> answer;

        for (int i = 0; i < p; i++) {
            vector<int> temp;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    temp.push_back(nums[j]);
                }
            }
            answer.push_back(move(temp));
        }

        return answer;
    }
};