class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numCount;
        int maxCount = 0;
        vector<int> result;
        result.reserve(k);

        for (int n : nums) {
            numCount[n]++;
            maxCount = max(maxCount, numCount[n]);
        }

        vector<vector<int>> buckets(maxCount + 1);

        for (const auto& [num, count] : numCount) {
            buckets[count].push_back(num);
        }

        for (int i = buckets.size() - 1; i >= 0; i--) {
            for (int n : buckets[i]) {
                result.push_back(n);
                k--;
                if (k == 0)
                    break;
            }
            if (k == 0)
                break;
        }

        return result;
    }
};