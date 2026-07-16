class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        if (size < 2)
            return false;

        int prefixSum = 0;
        unordered_map<int, int> sumMap = {{0, -1}};

        for (int i = 0; i < size; i++) {
            prefixSum = (prefixSum + nums[i]) % k;
            if (sumMap.count(prefixSum)) {
                if (i - sumMap[prefixSum] >= 2)
                    return true;
            } else
                sumMap[prefixSum] = i;
        }

        return false;
    }
};