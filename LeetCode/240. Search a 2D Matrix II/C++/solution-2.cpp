class Solution {
private:
    bool binarySearch(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return true;

            if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return false;
    }
    bool searchMat(vector<vector<int>>& matrix, int left, int right,
                   int target) {
        if (left > right)
            return false;

        int mid = left + (right - left) / 2;
        if (target >= matrix[mid].front() && target <= matrix[mid].back()) {
            if (binarySearch(matrix[mid], target))
                return true;
        }
        return searchMat(matrix, left, mid - 1, target) ||
               searchMat(matrix, mid + 1, right, target);
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return searchMat(matrix, 0, matrix.size() - 1, target);
    }
};