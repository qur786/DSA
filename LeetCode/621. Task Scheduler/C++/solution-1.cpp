class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int size = tasks.size();
        int t = 0;
        unordered_map<char, int> taskCount;
        auto comparator = [&](const char p1, const char p2) {
            return taskCount[p1] == taskCount[p2]
                       ? p1 > p2
                       : taskCount[p1] < taskCount[p2];
        };
        queue<pair<char, int>> q;
        priority_queue<char, vector<char>, decltype(comparator)> pq(comparator);
        for (char task : tasks)
            taskCount[task] += 1;
        for (const auto& [ch, count] : taskCount)
            pq.push(ch);

        while (!pq.empty() || !q.empty()) {
            t = pq.empty() ? q.front().second : t + 1;
            if (!q.empty()) {
                auto& front = q.front();

                if (front.second <= t) {
                    pq.push(front.first);
                    q.pop();
                }
            }

            if (!pq.empty()) {
                char ch = pq.top();
                pq.pop();
                taskCount[ch] -= 1;
                if (taskCount[ch] > 0)
                    q.emplace(ch, t + n + 1);
            }
        }

        return t;
    }
};