class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegrees(numCourses, 0);
        queue<int> nodes;
        vector<int> answer;
        answer.reserve(numCourses);

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

            answer.push_back(front);

            for (int child : adj[front]) {
                indegrees[child]--;
                if (!indegrees[child])
                    nodes.push(child);
            }
        }

        return answer.size() == numCourses;
    }
};