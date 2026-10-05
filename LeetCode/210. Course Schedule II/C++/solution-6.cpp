class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegrees(numCourses, 0);
        queue<int> nodes;
        vector<int> result;
        result.reserve(numCourses);

        for (const auto& pre : prerequisites) {
            int u = pre[0], v = pre[1];
            adj[v].push_back(u);
            indegrees[u]++;
        }

        for (int i = 0; i < numCourses; i++) {
            if (!indegrees[i])
                nodes.push(i);
        }

        while (!nodes.empty()) {
            auto front = nodes.front();
            nodes.pop();
            result.push_back(front);

            for (const auto& child : adj[front]) {
                indegrees[child]--;
                if (!indegrees[child])
                    nodes.push(child);
            }
        }

        if (result.size() != numCourses)
            return {};

        return result;
    }
};