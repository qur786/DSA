class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        long long prefixSum = 0;
        int size = nums.size();
        unordered_map<int, int> sumCount = {{0, 1}};
        int count = 0;

        for (int i = 0; i < size; i++) {
            prefixSum += nums[i];
            int t = prefixSum - k;

            if (sumCount.count(t))
                count += sumCount[t];
            sumCount[prefixSum]++;
        }

        return count;
    }
};