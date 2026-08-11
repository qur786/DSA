class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int maxOp = 0, left = 0, sum = accumulate(nums.begin(), nums.end(), 0),
            size = nums.size();
        int target = sum - x, currSum = 0;

        if (sum == x)
            return size;
        if (sum < x)
            return -1;

        for (int right = 0; right < size; right++) {
            currSum += nums[right];
            while (currSum > target) {
                currSum -= nums[left];
                left++;
            }

            if (currSum == target)
                maxOp = max(maxOp, right - left + 1);
        }

        int minOp = maxOp == 0 ? -1 : size - maxOp;

        return minOp;
    }
};