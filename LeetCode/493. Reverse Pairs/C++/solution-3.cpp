class Solution {
    int count = 0;
    void mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high)
            return;

        int mid = low + (high - low) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && nums[i] > 2LL * nums[j])
                j++;
            count += (j - (mid + 1));
        }
        merge(nums, low, mid, high);
    }
    void merge(vector<int>& nums, int low, int mid, int high) {
        int size1 = mid - low + 1, size2 = high - mid;
        vector<int> nums1(nums.begin() + low, nums.begin() + mid + 1),
            nums2(nums.begin() + mid + 1, nums.begin() + high + 1);
        int i = 0, j = 0, k = low;
        while (i < size1 && j < size2) {
            if (nums1[i] <= nums2[j]) {
                nums[k] = nums1[i];
                i++;
            } else {
                nums[k] = nums2[j];
                j++;
            }
            k++;
        }
        while (i < size1) {
            nums[k] = nums1[i];
            i++;
            k++;
        }
        while (j < size2) {
            nums[k] = nums2[j];
            j++;
            k++;
        }
    }

public:
    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);

        return count;
    }
};