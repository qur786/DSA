class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int size = prerequisites.size();
        vector<vector<int>> adj(numCourses);
        vector<int> inDegrees(numCourses, 0);
        vector<int> answer;
        answer.reserve(numCourses);

        for (const auto& pre : prerequisites) {
            int u = pre[0];
            int v = pre[1];

            adj[v].push_back(u);

            inDegrees[u]++;
        }

        queue<int> nodes;

        for (int i = 0; i < numCourses; i++)
            if (!inDegrees[i])
                nodes.push(i);

        while (!nodes.empty()) {
            int front = nodes.front();
            nodes.pop();
            answer.push_back(front);

            for (int neighbor : adj[front]) {
                inDegrees[neighbor]--;
                if (!inDegrees[neighbor])
                    nodes.push(neighbor);
            }
        }

        return answer.size() == numCourses;
    }
};