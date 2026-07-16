class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        int maxGap = 0, size = nums.size();
        auto [minIt, maxIt] = minmax_element(nums.begin(), nums.end());
        int minElement = *minIt, maxElement = *maxIt;

        int range = maxElement - minElement;
        int bucketSize = max(1, range / (size - 1));
        int bucketCount = range / bucketSize + 1;

        vector<pair<int, int>> buckets(bucketCount,
                                       make_pair(INT_MAX, INT_MIN));

        for (int i = 0; i < size; i++) {
            int bucketIndex = (nums[i] - minElement) / bucketSize;
            buckets[bucketIndex].first =
                min(buckets[bucketIndex].first, nums[i]);
            buckets[bucketIndex].second =
                max(buckets[bucketIndex].second, nums[i]);
        }

        int prevMax = buckets[0].second;

        for (int i = 1; i < size; i++) {
            if (buckets[i].first == INT_MAX)
                continue;
            maxGap = max(maxGap, buckets[i].first - prevMax);
            prevMax = buckets[i].second;
        }

        return maxGap;
    }
};