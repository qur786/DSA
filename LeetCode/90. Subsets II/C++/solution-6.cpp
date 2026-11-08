class Solution {
private:
    void solve(vector<vector<int>>& answer, vector<int>& nums,
               vector<int>& comb, int size, int index) {
        if (size == index) {
            answer.push_back(comb);
            return;
        }

        comb.push_back(nums[index]);
        solve(answer, nums, comb, size, index + 1);
        while (index < size - 1 && nums[index] == nums[index + 1])
            index++;
        comb.pop_back();
        solve(answer, nums, comb, size, index + 1);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        vector<int> comb;
        int size = nums.size();
        solve(answer, nums, comb, size, 0);
        return answer;
    }
};