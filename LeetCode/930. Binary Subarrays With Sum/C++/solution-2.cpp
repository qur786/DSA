class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int size = nums.size(), subArrayCount = 0, prefixSum = 0;
        unordered_map<int, int> sumCount = {{0, 1}};

        for (int right = 0; right < size; right++) {
            prefixSum += nums[right];
            if (sumCount.count(prefixSum - goal))
                subArrayCount += sumCount[prefixSum - goal];
            sumCount[prefixSum]++;
        }

        return subArrayCount;
    }
};