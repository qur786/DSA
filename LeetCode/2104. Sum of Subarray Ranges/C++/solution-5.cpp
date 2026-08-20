class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<int> incr, decr;
        long long maxSum = 0, minSum = 0;
        nums.push_back(INT_MAX);
        int size = nums.size();
        for (int right = 0; right < size; right++) {
            while (!decr.empty() && (nums[right] > nums[decr.top()])) {
                int currentIndex = decr.top();
                decr.pop();
                int left = decr.empty() ? -1 : decr.top();
                maxSum += (long long)(right - currentIndex) *
                          (currentIndex - left) * nums[currentIndex];
            }
            decr.push(right);
        }
        nums.pop_back();
        nums.push_back(INT_MIN);
        for (int right = 0; right < size; right++) {
            while (!incr.empty() && (nums[right] < nums[incr.top()])) {
                int currentIndex = incr.top();
                incr.pop();
                int left = incr.empty() ? -1 : incr.top();
                minSum += (long long)(right - currentIndex) *
                          (currentIndex - left) * nums[currentIndex];
            }
            incr.push(right);
        }
        nums.pop_back();
        return maxSum - minSum;
    }
};