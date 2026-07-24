class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> monotonicDecreasingNumIndices;
        int size = nums.size();
        vector<int> maximumValues;
        maximumValues.reserve(size - k + 1);

        for (int right = 0; right < size; right++) {
            while (!monotonicDecreasingNumIndices.empty() &&
                   nums[monotonicDecreasingNumIndices.back()] <= nums[right])
                monotonicDecreasingNumIndices.pop_back();
            while (!monotonicDecreasingNumIndices.empty() &&
                   (right - monotonicDecreasingNumIndices.front()) >= k)
                monotonicDecreasingNumIndices.pop_front();

            monotonicDecreasingNumIndices.push_back(right);

            if (right >= (k - 1))
                maximumValues.push_back(
                    nums[monotonicDecreasingNumIndices.front()]);
        }

        return maximumValues;
    }
};