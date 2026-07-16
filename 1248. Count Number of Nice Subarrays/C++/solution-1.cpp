class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int prefixSum = 0;
        int size = nums.size();
        int count = 0;
        unordered_map<int, int> sumMap = {{0, 1}};

        for (int i = 0; i < size; i++) {
            prefixSum += nums[i] % 2 == 0 ? 0 : 1;
            if (sumMap.count(prefixSum - k))
                count += sumMap[prefixSum - k];
            sumMap[prefixSum]++;
        }

        return count;
    }
};