class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int left = 0, size = nums.size(), totalSubArray = 0;
        int prefixSum = 0;
        unordered_map<int, int> sumCount = {{0, 1}};

        for (int right = 0; right < size; right++) {
            prefixSum += nums[right];
            int t = prefixSum - k;
            if (sumCount.count(t))
                totalSubArray += sumCount[t];
            sumCount[prefixSum]++;
        }

        return totalSubArray;
    }
};