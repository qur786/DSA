class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> countMap = {{0, 1}};
        int size = nums.size();
        int prefixSum = 0;
        int totalSubArrays = 0;

        for (int i = 0; i < size; i++) {
            prefixSum += nums[i];
            int target = prefixSum - k;

            if (countMap.count(target))
                totalSubArrays += countMap[target];

            countMap[prefixSum]++;
        }

        return totalSubArrays;
    }
};