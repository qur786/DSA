class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;
        int size = nums.size();

        for (int windowSize = 1; windowSize <= size; windowSize++) {
            for (int i = 0; i <= (size - windowSize); i++) {
                auto [minIt, maxIt] = minmax_element(
                    nums.begin() + i, nums.begin() + i + windowSize);
                int minValue = *minIt, maxValue = *maxIt;
                sum += maxValue - minValue;
            }
        }

        return sum;
    }
};