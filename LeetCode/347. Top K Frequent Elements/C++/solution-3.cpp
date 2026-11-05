class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int size = nums.size();
        unordered_map<int, int> countMap;
        vector<int> result;
        result.reserve(k);
        auto comparator = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        };
        for (int n : nums)
            countMap[n] += 1;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       decltype(comparator)>
            pq(comparator);
        for (const auto& [n, c] : countMap) {
            pq.emplace(c, n);
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