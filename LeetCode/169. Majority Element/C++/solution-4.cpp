class Solution {
private:
    int getMaj(vector<int>& nums, int left, int right) {
        int randomIndex = left + rand() % (right - left + 1);
        swap(nums[randomIndex], nums[right]);
        int pivotIndex = right, pivot = nums[right];

        int l = left, i = left, r = right;

        while (i <= r) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[l]);
                l++;
                i++;
            } else if (nums[i] > pivot) {
                swap(nums[i], nums[r]);
                r--;
            } else
                i++;
        }

        if ((r - l + 1) > nums.size() / 2)
            return pivot;

        if ((l - left) > (right - r))
            return getMaj(nums, left, l - 1);

        return getMaj(nums, r + 1, right);
    }

public:
    int majorityElement(vector<int>& nums) {
        return getMaj(nums, 0, nums.size() - 1);
    }
};