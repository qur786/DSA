class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        long long t = 0;
        int tasksCount = tasks.size();
        int serversCount = servers.size();
        vector<int> answer;
        answer.reserve(tasksCount);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
            availableServers;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<>>
            runningServers; // weight, index; time, index

        for (int i = 0; i < serversCount; i++)
            availableServers.emplace(servers[i], i);

        for (int i = 0; i < tasksCount; i++) {
            t = availableServers.empty() ? runningServers.top().first
                                         : max(t, static_cast<long long>(i));

            while (!runningServers.empty() && runningServers.top().first <= t) {
                auto [endAt, idx] = runningServers.top();
                runningServers.pop();
                availableServers.emplace(servers[idx], idx);
            }

            auto [w, idx] = availableServers.top();
            availableServers.pop();
            answer.push_back(idx);
            runningServers.emplace(t + tasks[i], idx);
        }

        return answer;
    }
};