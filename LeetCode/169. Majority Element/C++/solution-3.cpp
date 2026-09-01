class Solution {
private:
    int getMaj(vector<int>& nums, int left, int right) {
        int randomIndex = left + rand() % (right - left + 1);
        swap(nums[randomIndex], nums[right]);
        int l = left, m = left, r = right;
        int pivot = nums[right], pivotIndex = right;

        while (m <= r) {
            if (nums[m] == pivot)
                m++;
            else if (nums[m] < pivot) {
                swap(nums[m], nums[l]);
                l++;
                m++;
            } else {
                swap(nums[m], nums[r]);
                r--;
            }
        }

        if ((r - l + 1) > nums.size() / 2)
            return pivot;

        if ((right - r) > (l - left))
            return getMaj(nums, r + 1, right);

        return getMaj(nums, left, l - 1);
    }

public:
    int majorityElement(vector<int>& nums) {
        return getMaj(nums, 0, nums.size() - 1);
    }
};