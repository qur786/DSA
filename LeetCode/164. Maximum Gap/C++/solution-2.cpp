class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;
        int size = nums.size();
        auto [minIt, maxIt] = minmax_element(nums.begin(), nums.end());
        int minElement = *minIt, maxElement = *maxIt;
        int maxGap = maxElement - minElement;
        if (maxGap == 0)
            return 0;

        int avgGap = max(1, maxGap / (size - 1));
        int bucketCount = maxGap / avgGap + 1;
        vector<pair<int, int>> buckets(bucketCount,
                                       make_pair(INT_MAX, INT_MIN));
        int ans = INT_MIN;

        for (int i = 0; i < size; i++) {
            int index = (nums[i] - minElement) / avgGap;
            buckets[index].first = min(buckets[index].first, nums[i]);
            buckets[index].second = max(buckets[index].second, nums[i]);
        }

        int prevMax = minElement;

        for (int i = 0; i < bucketCount; i++) {
            if (buckets[i].first == INT_MAX)
                continue;
            ans = max(ans, buckets[i].first - prevMax);
            prevMax = buckets[i].second;
        }

        return ans;
    }
};