class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int size = tasks.size();
        long long t = 0;

        vector<int> answer;
        answer.reserve(size);
        vector<int> indices(size);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(),
             [&](int a, int b) { return tasks[a][0] < tasks[b][0]; });
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int idx = 0;
        while (idx < size || !pq.empty()) {
            if (pq.empty())
                t = max(t, static_cast<long long>(tasks[indices[idx]][0]));

            while (idx < size && tasks[indices[idx]][0] <= t) {
                pq.emplace(tasks[indices[idx]][1], indices[idx]);
                idx += 1;
            }

            auto [pt, i] = pq.top();
            pq.pop();
            t = max(t, static_cast<long long>(tasks[i][0])) + pt;
            answer.push_back(i);
        }

        return answer;
    }
};