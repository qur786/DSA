class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int size = prerequisites.size();
        vector<int> inDegrees(numCourses, 0);
        vector<int> answer;
        answer.reserve(numCourses);
        vector<vector<int>> adj(numCourses);
        queue<int> nodes;

        for (const auto& pre : prerequisites) {
            int u = pre[0];
            int v = pre[1];

            adj[v].push_back(u);
            inDegrees[u]++;
        }

        for (int i = 0; i < numCourses; i++)
            if (!inDegrees[i])
                nodes.push(i);

        while (!nodes.empty()) {
            auto front = nodes.front();
            nodes.pop();
            answer.push_back(front);

            for (int child : adj[front]) {
                inDegrees[child]--;
                if (!inDegrees[child])
                    nodes.push(child);
            }
        }

        if (answer.size() != numCourses)
            return {};

        return answer;
    }
};