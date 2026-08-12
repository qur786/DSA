class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> sumIndices = {{0, -1}};
        int prefixSum = 0;
        int size = nums.size();
        int maxLen = 0;

        for (int right = 0; right < size; right++) {
            prefixSum += nums[right] == 1 ? 1 : -1;

            if (sumIndices.count(prefixSum))
                maxLen = max(maxLen, right - sumIndices[prefixSum]);
            else
                sumIndices[prefixSum] = right;
        }

        return maxLen;
    }
};