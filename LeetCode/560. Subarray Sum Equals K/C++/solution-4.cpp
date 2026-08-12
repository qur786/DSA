class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        long long prefixSum = 0;
        int size = nums.size(), subArrayCount = 0;
        unordered_map<int, long long> sumCount = {{0, 1}};

        for (int right = 0; right < size; right++) {
            prefixSum += nums[right];

            if (sumCount.count(prefixSum - k))
                subArrayCount += sumCount[prefixSum - k];
            sumCount[prefixSum]++;
        }

        return subArrayCount;
    }
};