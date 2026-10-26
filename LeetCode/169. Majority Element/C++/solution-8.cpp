class Solution {
private:
    int solve(vector<int>& nums, int left, int right) {
        int randomIndex = left + rand() % (right - left + 1);
        swap(nums[randomIndex], nums[right]);
        int pivot = nums[right];

        int i = left, l = left, r = right;

        while (i <= r) {
            if (nums[i] == pivot)
                i++;
            else if (nums[i] < pivot) {
                swap(nums[i], nums[l]);
                i++;
                l++;
            } else {
                swap(nums[i], nums[r]);
                r--;
            }
        }

        int midLen = r - l + 1;

        if (midLen > nums.size() / 2)
            return pivot;

        if ((l - left) > (right - r))
            return solve(nums, left, l - 1);

        return solve(nums, r + 1, right);
    }

public:
    int majorityElement(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }
};