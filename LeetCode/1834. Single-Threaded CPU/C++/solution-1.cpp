class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int size = tasks.size();
        long long t = 0;
        vector<int> answer;
        answer.reserve(size);
        deque<int> availableProcesses(size);

        iota(availableProcesses.begin(), availableProcesses.end(), 0);
        sort(availableProcesses.begin(), availableProcesses.end(),
             [&](int a, int b) {
                 return tasks[a][0] == tasks[b][0] ? tasks[a][1] < tasks[b][1]
                                                   : tasks[a][0] < tasks[b][0];
             });

        auto comparator = [&](const auto& p1, const auto& p2) {
            return p1.second == p2.second ? p1.first > p2.first
                                          : p1.second > p2.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       decltype(comparator)>
            pq(comparator);

        while (!pq.empty() || !availableProcesses.empty()) {
            if (pq.empty()) {
                t = max(t, static_cast<long long>(
                               tasks[availableProcesses.front()][0]));
                pq.emplace(availableProcesses.front(),
                           tasks[availableProcesses.front()][1]);
                availableProcesses.pop_front();
            }
            while (!availableProcesses.empty() &&
                   tasks[availableProcesses.front()][0] <= t) {
                pq.emplace(availableProcesses.front(),
                           tasks[availableProcesses.front()][1]);
                availableProcesses.pop_front();
            }

            auto [idx, pt] = pq.top();
            t = max(static_cast<long long>(tasks[idx][0]), t) + pt;
            pq.pop();

            answer.push_back(idx);
        }

        return answer;
    }
};