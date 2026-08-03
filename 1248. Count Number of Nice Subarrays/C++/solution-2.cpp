class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int size = nums.size(), subArrayCount = 0, prefixSum = 0;
        unordered_map<int, int> oddCountMap = {{0, 1}};

        for (int right = 0; right < size; right++) {
            prefixSum += nums[right] % 2;
            if (oddCountMap.count(prefixSum - k))
                subArrayCount += oddCountMap[prefixSum - k];
            oddCountMap[prefixSum]++;
        }

        return subArrayCount;
    }
};