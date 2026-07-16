class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int size = nums.size();
        vector<int> prefixSum(size + 1, 0);
        for (int i = 0; i < size; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        for (int i = 0; i < size; i++) {
            if (prefixSum[i] == (prefixSum[size] - prefixSum[i + 1]))
                return i;
        }

        return -1;
    }
};