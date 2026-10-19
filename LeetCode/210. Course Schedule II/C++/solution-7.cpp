class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> answer;
        answer.reserve(numCourses);
        vector<int> indegrees(numCourses, 0);
        queue<int> nodes;

        for (const auto& pre : prerequisites) {
            int u = pre[0], v = pre[1];
            indegrees[u]++;
            adj[v].push_back(u);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!indegrees[i])
                nodes.emplace(i);
        }

        while (!nodes.empty()) {
            auto front = nodes.front();
            nodes.pop();

            answer.push_back(front);

            for (int child : adj[front]) {
                indegrees[child]--;
                if (!indegrees[child])
                    nodes.emplace(child);
            }
        }

        if (answer.size() != numCourses)
            return {};

        return answer;
    }
};