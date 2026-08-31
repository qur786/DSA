class Solution {
private:
    int findMaj(vector<int>& nums, int left, int right) {
        int size = nums.size();
        int random = left + rand() % (right - left + 1);
        swap(nums[random], nums[right]);

        int pivotIndex = right, pivot = nums[right];
        int l = left, i = left, r = right;

        while (i <= r) {
            if (nums[i] == pivot)
                i++;
            else if (nums[i] < pivot) {
                swap(nums[i], nums[r]);
                r--;
            } else {
                swap(nums[i], nums[l]);
                i++;
                l++;
            }
        }

        int gap = r - l + 1;

        if (gap > size / 2)
            return pivot;

        if ((right - r) > (l - left))
            return findMaj(nums, r + 1, right);

        return findMaj(nums, left, l - 1);
    }

public:
    int majorityElement(vector<int>& nums) {
        return findMaj(nums, 0, nums.size() - 1);
    }
};