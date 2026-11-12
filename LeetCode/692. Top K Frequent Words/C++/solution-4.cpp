class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> countMap;
        auto comparator = [&](const auto& a, const auto& b) {
            return countMap[a] == countMap[b] ? a < b
                                              : countMap[a] > countMap[b];
        };
        priority_queue<string, vector<string>, decltype(comparator)> pq(
            comparator);
        vector<string> result;
        result.reserve(k);

        for (const auto& word : words)
            countMap[word]++;

        for (const auto& [word, count] : countMap) {
            pq.push(word);
            if (pq.size() > k)
                pq.pop();
        }

        while (!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};