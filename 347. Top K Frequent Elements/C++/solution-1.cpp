class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        int maxCount = 0;
        vector<int> result;
        result.reserve(k);

        for (int n : nums) {
            freqMap[n]++;
            maxCount = max(maxCount, freqMap[n]);
        }

        vector<vector<int>> buckets(maxCount + 1);

        for (const auto& [num, count] : freqMap) {
            buckets[count].push_back(num); // Or this can be done in a reverse
                                           // order for better iteration later
        }

        for (auto it = buckets.rbegin(); it != buckets.rend(); it++) {
            for (const int& n : *it) {
                if (result.size() == k)
                    return result;
                result.push_back(n);
            }
        }

        return result;
    }
};