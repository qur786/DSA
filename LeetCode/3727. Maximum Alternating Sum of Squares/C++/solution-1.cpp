class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for (int& n : nums)
            n = abs(n);
        sort(nums.begin(), nums.end(), greater<int>());
        long long sum1 = 0, sum2 = 0;
        int size1 = (nums.size() + 1) / 2;
        int size2 = nums.size();

        for (int i = 0; i < size1; i++) {
            sum1 += nums[i] * nums[i];
        }
        for (int i = size1; i < size2; i++) {
            sum2 += nums[i] * nums[i];
        }

        return sum1 - sum2;
    }
};