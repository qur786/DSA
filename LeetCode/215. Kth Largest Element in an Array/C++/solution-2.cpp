class Solution {
private:
    int findKth(vector<int>& nums, int left, int right, int k) {
        int randomIndex = left + rand() % (right - left + 1);
        swap(nums[randomIndex], nums[right]);
        int pivotIndex = right, pivot = nums[right];
        int l = left, m = left, r = right;

        while (m <= r) {
            if (nums[m] == pivot)
                m++;
            else if (nums[m] > pivot) {
                swap(nums[m], nums[l]);
                l++;
                m++;
            } else {
                swap(nums[m], nums[r]);
                r--;
            }
        }

        if (k - 1 < l)
            return findKth(nums, left, l - 1, k);
        if (k - 1 > r)
            return findKth(nums, r + 1, right, k);

        return pivot;
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKth(nums, 0, nums.size() - 1, k);
    }
};