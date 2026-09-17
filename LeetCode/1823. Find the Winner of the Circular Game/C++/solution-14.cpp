class Solution {
private:
    int findWin(vector<int>& nums, int k, int startIndex) {
        if (nums.size() == 1)
            return nums[0];
        int size = nums.size();
        int pos = (startIndex + k - 1) % size;
        nums.erase(nums.begin() + pos);

        return findWin(nums, k, pos);
    }

public:
    int findTheWinner(int n, int k) {
        vector<int> nums(n);
        iota(nums.begin(), nums.end(), 1);
        return findWin(nums, k, 0);
    }
};