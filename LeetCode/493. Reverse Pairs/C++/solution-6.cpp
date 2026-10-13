class Solution {
private:
    int count = 0;
    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> nums1(nums.begin() + left, nums.begin() + mid + 1);
        vector<int> nums2(nums.begin() + mid + 1, nums.begin() + right + 1);

        int i = 0, j = 0, k = left;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j]) {
                nums[k] = nums1[i];
                i++;
            } else {
                nums[k] = nums2[j];
                j++;
            }
            k++;
        }

        while (i < nums1.size()) {
            nums[k] = nums1[i];
            i++;
            k++;
        }

        while (j < nums2.size()) {
            nums[k] = nums2[j];
            j++;
            k++;
        }
    }
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && (long long)nums[i] > (long long)2 * nums[j])
                j++;
            count += (j - (mid + 1));
        }
        merge(nums, left, mid, right);
    }

public:
    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);

        return count;
    }
};