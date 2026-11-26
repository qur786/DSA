class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int size = tasks.size();
        long long t = 0;
        vector<int> answer;
        answer.reserve(size);
        vector<int> availableProcesses(size);
        int availableIndex = 0;

        iota(availableProcesses.begin(), availableProcesses.end(), 0);
        sort(availableProcesses.begin(), availableProcesses.end(),
             [&](int a, int b) { return tasks[a][0] < tasks[b][0]; });

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        while (!pq.empty() || availableIndex < size) {
            if (pq.empty()) {
                t = max(t, static_cast<long long>(
                               tasks[availableProcesses[availableIndex]][0]));
            }

            while (availableIndex < size &&
                   tasks[availableProcesses[availableIndex]][0] <= t) {
                pq.emplace(tasks[availableProcesses[availableIndex]][1],
                           availableProcesses[availableIndex]);
                availableIndex += 1;
            }

            auto [pt, idx] = pq.top();
            t = max(static_cast<long long>(tasks[idx][0]), t) + pt;
            pq.pop();

            answer.push_back(idx);
        }

        return answer;
    }
};