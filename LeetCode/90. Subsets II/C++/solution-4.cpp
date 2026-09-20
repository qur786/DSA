class Solution {
private:
    void createSub(vector<vector<int>>& answer, vector<int>& nums,
                   vector<int>& sub, int size, int index) {
        if (size == index) {
            answer.push_back(sub);
            return;
        }

        sub.push_back(nums[index]);
        createSub(answer, nums, sub, size, index + 1);
        while (index < size - 1 && nums[index] == nums[index + 1]) {
            index++;
        }
        sub.pop_back();
        createSub(answer, nums, sub, size, index + 1);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        vector<int> sub;
        int size = nums.size();
        createSub(answer, nums, sub, size, 0);

        return answer;
    }
};