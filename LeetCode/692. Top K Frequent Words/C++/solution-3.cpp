class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> result;
        result.reserve(k);
        unordered_map<string, int> countMap;
        auto comparator = [](const pair<string, int>& a,
                             const pair<string, int>& b) {
            return a.second == b.second ? a.first < b.first
                                        : a.second > b.second;
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>,
                       decltype(comparator)>
            pq(comparator);

        for (const auto& word : words)
            countMap[word] += 1;

        for (const auto& [word, count] : countMap) {
            pq.emplace(word, count);
            if (pq.size() > k)
                pq.pop();
        }

        while (!pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};