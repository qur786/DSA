class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        long long t = 0;
        int size = tasks.size();
        unordered_map<char, int> charCount;

        for (char c : tasks)
            charCount[c]++;

        priority_queue<pair<int, char>> pq;
        queue<pair<char, int>> q;

        for (const auto& [ch, count] : charCount)
            pq.emplace(count, ch);

        while (!pq.empty() || !q.empty()) {
            t = pq.empty() ? max(t, static_cast<long long>(q.front().second))
                           : t + 1;

            while (!q.empty() && q.front().second <= t) {
                pq.emplace(charCount[q.front().first], q.front().first);
                q.pop();
            }

            auto [count, ch] = pq.top();
            pq.pop();
            charCount[ch]--;
            if (charCount[ch] > 0)
                q.emplace(ch, t + n + 1);
        }

        return t;
    }
};