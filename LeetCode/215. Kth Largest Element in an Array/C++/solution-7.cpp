class Solution {
private:
    int solve(vector<int>& nums, int left, int right, int k) {
        int randomIndex = left + rand() % (right - left + 1);
        swap(nums[randomIndex], nums[right]);
        int pivot = nums[right];

        int l = left, r = right, i = left;

        while (i <= r) {
            if (nums[i] == pivot)
                i++;
            else if (nums[i] < pivot) {
                swap(nums[i], nums[r]);
                r--;
            } else {
                swap(nums[i], nums[l]);
                l++;
                i++;
            }
        }

        if (k - 1 <= l - 1)
            return solve(nums, left, l - 1, k);
        if (k - 1 >= r + 1)
            return solve(nums, r + 1, right, k);

        return pivot;
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        return solve(nums, 0, nums.size() - 1, k);
    }
};