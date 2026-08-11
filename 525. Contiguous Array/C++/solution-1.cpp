class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int size = nums.size();
        int prefixSum = 0, maxLen = 0;
        unordered_map<int, int> sumMap = {{0, -1}};

        for (int i = 0; i < size; i++) {
            prefixSum += nums[i] == 0 ? -1 : 1;
            if (sumMap.count(prefixSum))
                maxLen = max(maxLen, i - sumMap[prefixSum]);
            else
                sumMap[prefixSum] = i;
        }

        return maxLen;
    }
};