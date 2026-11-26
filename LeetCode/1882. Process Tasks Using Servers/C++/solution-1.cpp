class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int serversCount = servers.size();
        int tasksCount = tasks.size();
        long long t = 0;

        vector<int> answer;
        answer.reserve(tasksCount);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
            availableServers;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<>>
            workingServers;

        for (int i = 0; i < serversCount; i++)
            availableServers.emplace(servers[i], i);

        for (int i = 0; i < tasksCount; i++) {
            t = availableServers.empty() ? workingServers.top().first
                                         : max(t, static_cast<long long>(i));

            while (!workingServers.empty() && workingServers.top().first <= t) {
                auto [finishedAt, index] = workingServers.top();
                workingServers.pop();
                availableServers.emplace(servers[index], index);
            }

            auto [weight, index] = availableServers.top();
            availableServers.pop();
            workingServers.emplace(t + tasks[i], index);
            answer.push_back(index);
        }

        return answer;
    }
};