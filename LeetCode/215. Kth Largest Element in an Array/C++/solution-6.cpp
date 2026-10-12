class Solution {
private:
    int findKth(vector<int>& nums, int k, int left, int right) {
        int randomIndex = left + rand() % (right - left + 1);
        swap(nums[right], nums[randomIndex]);
        int pivot = nums[right];
        int i = left, l = left, r = right;

        while (i <= r) {
            if (nums[i] == pivot)
                i++;
            else if (nums[i] < pivot) {
                swap(nums[i], nums[r]);
                r--;
            } else {
                swap(nums[l], nums[i]);
                i++;
                l++;
            }
        }

        if (k - 1 < l)
            return findKth(nums, k, left, l - 1);
        if (k - 1 > r)
            return findKth(nums, k, r + 1, right);

        return pivot;
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKth(nums, k, 0, nums.size() - 1);
    }
};