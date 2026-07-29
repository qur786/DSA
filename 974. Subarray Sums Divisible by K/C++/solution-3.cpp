class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int remainder = 0;
        int size = nums.size();
        int totalSubArrays = 0;
        unordered_map<int, int> remainderMap = {{0, 1}};

        for (int i = 0; i < size; i++) {
            remainder = ((remainder + nums[i]) % k + k) % k;

            totalSubArrays += remainderMap[remainder]++;
        }

        return totalSubArrays;
    }
};