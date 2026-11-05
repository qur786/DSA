class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> countMap;
        vector<string> result;
        result.reserve(k);

        for (const auto& word : words) {
            countMap[word] += 1;
        }

        auto comparator = [](const pair<int, string>& a,
                             const pair<int, string>& b) {
            return a.first == b.first ? a.second < b.second : a.first > b.first;
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>,
                       decltype(comparator)>
            pq(comparator);

        for (const auto& [word, count] : countMap) {
            pq.emplace(count, word);
            if (pq.size() > k)
                pq.pop();
        }

        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};