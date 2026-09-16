class Solution {
private:
    void createSubSet(vector<vector<int>>& answer, vector<int>& nums,
                      vector<int>& sub, int index, int size) {
        if (index == size) {
            answer.push_back(sub);
            return;
        }
        sub.push_back(nums[index]);
        createSubSet(answer, nums, sub, index + 1, size);
        while (index < size - 1 && nums[index] == nums[index + 1])
            index++;
        sub.pop_back();
        createSubSet(answer, nums, sub, index + 1, size);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<vector<int>> answer;
        vector<int> sub;
        createSubSet(answer, nums, sub, 0, size);
        return answer;
    }
};