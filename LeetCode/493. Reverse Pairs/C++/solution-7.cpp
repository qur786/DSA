class Solution {
private:
    void mergeSort(vector<int>& nums, int left, int right, int& count) {
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;

        mergeSort(nums, left, mid, count);
        mergeSort(nums, mid + 1, right, count);
        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && (long long)nums[i] > (long long)2 * nums[j])
                j++;
            count += (j - (mid + 1));
        }
        merge(nums, left, mid, right);
    }
    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> nums1(nums.begin() + left, nums.begin() + mid + 1);
        vector<int> nums2(nums.begin() + mid + 1, nums.begin() + right + 1);

        int i = 0, j = 0, k = left;
        int size1 = nums1.size(), size2 = nums2.size();

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
        int count = 0;
        mergeSort(nums, 0, nums.size() - 1, count);

        return count;
    }
};