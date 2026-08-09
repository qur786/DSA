class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        int prefixSum = 0;
        int count = 0;
        unordered_map<int, int> sumCount = {{0, 1}};

        for (int i = 0; i < size; i++) {
            prefixSum += nums[i];

            if (sumCount.count(prefixSum - k))
                count += sumCount[prefixSum - k];
            sumCount[prefixSum]++;
        }

        return count;
    }
};