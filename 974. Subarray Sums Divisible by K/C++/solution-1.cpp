class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int remainder = 0, totalSubarrays = 0;
        unordered_map<int, int> remainderMap = {{0, 1}};

        for (int n : nums) {
            remainder = ((remainder + n) % k + k) % k;
            totalSubarrays += remainderMap[remainder]++;
        }

        return totalSubarrays;
    }
};