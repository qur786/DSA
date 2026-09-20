class Solution {
private:
    void createSub(vector<vector<int>>& answer, vector<int>& nums,
                   vector<int>& comb, int size, int index) {
        if (size == index) {
            answer.push_back(comb);
            return;
        }

        comb.push_back(nums[index]);
        createSub(answer, nums, comb, size, index + 1);
        comb.pop_back();
        createSub(answer, nums, comb, size, index + 1);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> comb;
        int size = nums.size();
        createSub(answer, nums, comb, size, 0);

        return answer;
    }
};