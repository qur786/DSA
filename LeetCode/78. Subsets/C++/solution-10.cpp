class Solution {
private:
    void solve(vector<vector<int>> & answer, vector<int> & comb, vector<int> & nums, int index, int size) {
        if (index == size) {
            answer.push_back(comb);

            return;
        }

        comb.push_back(nums[index]);
        solve(answer, comb, nums, index + 1, size);
        comb.pop_back();
        solve(answer, comb, nums, index + 1, size);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> comb;
        int size = nums.size();
        solve(answer, comb, nums, 0, size);
        return answer;
    }
};