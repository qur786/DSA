class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer(1);
        for (int n : nums) {
            int currentSize = answer.size();
            for (int i = 0; i < currentSize; i++) {
                auto vec = answer[i];
                vec.push_back(n);
                answer.push_back(vec);
            }
        }
        return answer;
    }
};