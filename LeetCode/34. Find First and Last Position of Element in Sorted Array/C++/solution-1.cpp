class Solution {
public:
    int modifiedBinarySearch(vector<int>& nums, int target, bool isLeft) {
        int low = 0, high = nums.size() - 1, result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                result = mid;
                if (isLeft)
                    high = mid - 1;
                else
                    low = mid + 1;
            } else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return result;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {modifiedBinarySearch(nums, target, true),
                modifiedBinarySearch(nums, target, false)};
    }
};