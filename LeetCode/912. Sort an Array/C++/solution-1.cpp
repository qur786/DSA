class Solution {
private:
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }
    void merge(vector<int>& nums, int left, int mid, int right) {
        int size1 = mid - left + 1, size2 = right - mid;
        vector<int> nums1(nums.begin() + left, nums.begin() + mid + 1),
            nums2(nums.begin() + mid + 1, nums.begin() + right + 1);
        int p = 0, q = 0, i = left;

        while (i <= right && p < size1 && q < size2) {
            if (nums1[p] <= nums2[q]) {
                nums[i] = nums1[p];
                p++;
            } else {
                nums[i] = nums2[q];
                q++;
            }
            i++;
        }

        while (p < size1) {
            nums[i] = nums1[p];
            p++;
            i++;
        }
        while (q < size2) {
            nums[i] = nums2[q];
            q++;
            i++;
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        this->mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};