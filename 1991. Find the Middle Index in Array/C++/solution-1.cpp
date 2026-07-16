class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int size = nums.size();
        vector<int> rightPrefixSum(size, 0), leftPrefixSum(size, 0);

        for (int i = 0; i < size; i++) {
            leftPrefixSum[i] = i == 0 ? 0 : leftPrefixSum[i - 1] + nums[i - 1];
        }
        for (int i = size - 1; i >= 0; i--) {
            rightPrefixSum[i] =
                i == (size - 1) ? 0 : rightPrefixSum[i + 1] + nums[i + 1];
        }

        for (int i = 0; i < size; i++) {
            if (leftPrefixSum[i] == rightPrefixSum[i])
                return i;
        }

        return -1;
    }
};