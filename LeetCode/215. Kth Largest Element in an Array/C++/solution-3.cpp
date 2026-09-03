class Solution {
private:
    int findKth(vector<int>& nums, int left, int right, int k) {
        int randomIndex = left + rand() % (right - left + 1);
        swap(nums[randomIndex], nums[right]);
        int pivotIndex = right, pivot = nums[right];

        int l = left, i = left, r = right;

        while (i <= r) {
            if (nums[i] > pivot) {
                swap(nums[l], nums[i]);
                i++;
                l++;
            } else if (nums[i] < pivot) {
                swap(nums[r], nums[i]);
                r--;
            } else
                i++;
        }

        if (l > k - 1)
            return findKth(nums, left, l - 1, k);
        if (r < k - 1)
            return findKth(nums, r + 1, right, k);

        return pivot;
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKth(nums, 0, nums.size() - 1, k);
    }
};