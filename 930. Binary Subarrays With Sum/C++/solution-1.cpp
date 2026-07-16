class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int size = nums.size();
        int count = 0;
        int prefixSum = 0;
        unordered_map<int, int> sumCount = {{0, 1}};

        for (int i = 0; i < size; i++) {
            prefixSum += nums[i];
            if (sumCount.count(prefixSum - goal))
                count += sumCount[prefixSum - goal];
            sumCount[prefixSum]++;
        }

        return count;
    }
};