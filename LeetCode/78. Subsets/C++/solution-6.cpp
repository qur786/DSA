class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subCount = pow(2, n);
        vector<vector<int>> answer;

        for (int i = 0; i < subCount; i++) {
            vector<int> sub;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    sub.push_back(nums[j]);
                }
            }
            answer.push_back(sub);
        }

        return answer;
    }
};