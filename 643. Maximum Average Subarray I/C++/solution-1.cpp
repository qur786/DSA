class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAverage = INT_MIN, sum = 0;
        int size = nums.size(), left = 0;

        for (int right = 0; right < size; right++) {
            sum += nums[right];

            if ((right - left + 1) == k) {
                maxAverage = max(sum / k, maxAverage);
                sum -= nums[left];
                left++;
            }
        }

        return maxAverage;
    }
};