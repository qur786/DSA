class Solution {
private:
    int findKth(vector<int>& nums, int k, int left, int right) {
        int randomIndex = left + rand() % (right - left + 1);
        swap(nums[randomIndex], nums[right]);
        int pivot = nums[right];
        int l = left, r = right, i = left;

        while (i <= r) {
            if (nums[i] == pivot)
                i++;
            else if (nums[i] > pivot) {
                swap(nums[i], nums[l]);
                i++;
                l++;
            } else {
                swap(nums[i], nums[r]);
                r--;
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