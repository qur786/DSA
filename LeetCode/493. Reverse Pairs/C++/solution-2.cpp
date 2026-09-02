class Solution {
private:
    int count = 0;
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }
        merge(nums, left, mid, right);
    }
    void merge(vector<int>& nums, int left, int mid, int right) {
        int size1 = mid - left + 1, size2 = right - mid;
        vector<int> nums1(nums.begin() + left, nums.begin() + mid + 1),
            nums2(nums.begin() + mid + 1, nums.begin() + right + 1);
        int i = 0, j = 0, k = left;
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