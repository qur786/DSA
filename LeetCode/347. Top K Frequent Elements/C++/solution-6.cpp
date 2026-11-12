class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        auto comparator = [&](const int a, const int b) {
            return countMap[a] > countMap[b];
        };

        priority_queue<int, vector<int>, decltype(comparator)> pq(comparator);

        for (int n : nums)
            countMap[n]++;
        for (const auto& [value, count] : countMap) {
            pq.push(value);
            if (pq.size() > k)
                pq.pop();
        }

        vector<int> result;
        result.reserve(k);

        while (!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }

        return result;
    }
};