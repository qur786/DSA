class Solution {
private:
    int getMaj(vector<int>& nums, int left, int right) {
        int randomIndex = left + rand() % (right - left + 1);
        swap(nums[right], nums[randomIndex]);
        int pivot = nums[right];

        int i = left, l = left, r = right;

        while (i <= r) {
            if (nums[i] == pivot)
                i++;
            else if (nums[i] < pivot) {
                swap(nums[i], nums[l]);
                i++;
                l++;
            } else {
                swap(nums[i], nums[r]);
                r--;
            }
        }

        if (l - left > r - l + 1)
            return getMaj(nums, left, l - 1);
        if (right - r > r - l + 1)
            return getMaj(nums, r + 1, right);

        return pivot;
    }

public:
    int majorityElement(vector<int>& nums) {
        return getMaj(nums, 0, nums.size() - 1);
    }
};