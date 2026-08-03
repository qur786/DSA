class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int size = nums.size();
        vector<int> prefixSum(size + 1, 0);

        for (int i = 1; i <= size; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }

        for (int i = 1; i <= size; i++)
            if (prefixSum[i - 1] == (prefixSum[size] - prefixSum[i]))
                return i - 1;

        return -1;
    }
};