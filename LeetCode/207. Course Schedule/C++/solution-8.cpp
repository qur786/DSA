class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses, 0);
        vector<int> answer;
        answer.reserve(numCourses);
        vector<vector<int>> adj(numCourses);
        queue<int> nodes;

        for (const auto& pre : prerequisites) {
            int u = pre[0], v = pre[1];
            indegrees[u]++;
            adj[v].push_back(u);
        }

        for (int i = 0; i < numCourses; i++)
            if (!indegrees[i])
                nodes.emplace(i);

        while (!nodes.empty()) {
            auto node = nodes.front();
            nodes.pop();

            answer.push_back(node);

            for (int child : adj[node]) {
                indegrees[child]--;
                if (!indegrees[child])
                    nodes.emplace(child);
            }
        }

        return answer.size() == numCourses;
    }
};