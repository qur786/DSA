class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int size = nums.size();
        vector<int> leftSum(size, 0), rightSum(size, 0);

        for (int i = 1; i < size; i++) {
            leftSum[i] = leftSum[i - 1] + nums[i - 1];
            rightSum[size - i - 1] = rightSum[size - i] + nums[size - i];
        }

        for (int i = 0; i < size; i++)
            if (leftSum[i] == rightSum[i])
                return i;

        return -1;
    }
};