class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;
        int size = nums.size();

        for (int windowSize = 1; windowSize <= size; windowSize++) {
            deque<int> monotonicIncreasingQ, monotonicDecreasingQ;
            int minValue = 0, maxValue = 0;
            for (int i = 0; i < size; i++) {
                while (!monotonicIncreasingQ.empty() &&
                       nums[monotonicIncreasingQ.back()] >= nums[i])
                    monotonicIncreasingQ.pop_back();
                while (!monotonicIncreasingQ.empty() &&
                       (i - monotonicIncreasingQ.front()) >= windowSize)
                    monotonicIncreasingQ.pop_front();

                monotonicIncreasingQ.push_back(i);

                while (!monotonicDecreasingQ.empty() &&
                       nums[monotonicDecreasingQ.back()] <= nums[i])
                    monotonicDecreasingQ.pop_back();
                while (!monotonicDecreasingQ.empty() &&
                       (i - monotonicDecreasingQ.front()) >= windowSize)
                    monotonicDecreasingQ.pop_front();

                monotonicDecreasingQ.push_back(i);

                if (i >= (windowSize - 1)) {
                    minValue = nums[monotonicIncreasingQ.front()];
                    maxValue = nums[monotonicDecreasingQ.front()];
                }
                sum += maxValue - minValue;
            }
        }

        return sum;
    }
};