class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int size = nums.size();
        unordered_map<int, int> remainderMap = {{0, 1}};
        int remainder = 0, count = 0;
        for (int i = 0; i < size; i++) {
            remainder = (((remainder + nums[i]) % k) + k) % k;
            if (remainderMap.count(remainder))
                count += remainderMap[remainder];
            remainderMap[remainder]++;
        }

        return count;
    }
};