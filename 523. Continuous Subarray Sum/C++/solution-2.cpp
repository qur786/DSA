class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int remainder = 0, size = nums.size();
        unordered_map<int, int> remainderMap = {{0, -1}};

        for (int right = 0; right < size; right++) {
            remainder = (remainder + nums[right]) % k;
            if (remainderMap.count(remainder)) {
                if ((right - remainderMap[remainder]) >= 2)
                    return true;
            } else
                remainderMap[remainder] = right;
        }

        return false;
    }
};