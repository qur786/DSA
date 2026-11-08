class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        result.reserve(k);
        unordered_map<int, int> countMap;
        auto comparator = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        };
        for (int n : nums)
            countMap[n] += 1;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       decltype(comparator)>
            pq(comparator);

        for (const auto& [n, count] : countMap) {
            pq.emplace(count, n);
            if (pq.size() > k)
                pq.pop();
        }

        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};