class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int size = tasks.size();
        int t = 0;
        unordered_map<char, int> taskCount;
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        for (char task : tasks)
            taskCount[task] += 1;
        for (const auto& [ch, count] : taskCount)
            pq.push(count);

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
                int count = pq.top();
                pq.pop();
                count -= 1;
                if (count > 0)
                    q.emplace(count, t + n + 1);
            }
        }

        return t;
    }
};