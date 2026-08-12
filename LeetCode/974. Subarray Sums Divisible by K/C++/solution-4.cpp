class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int size = nums.size();
        unordered_map<int, int> remainderCount = {{0, 1}};
        int count = 0, remainder = 0;

        for (int i = 0; i < size; i++) {
            remainder = ((remainder + nums[i]) % k + k) % k;
            count += remainderCount[remainder];
            remainderCount[remainder]++;
        }

        return count;
    }
};