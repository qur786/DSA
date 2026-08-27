class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegrees(numCourses);
        queue<int> nodes;

        for (const auto& pre : prerequisites) {
            int x = pre[0], y = pre[1];
            adj[y].push_back(x);
            inDegrees[x]++;
        }

        for (int i = 0; i < numCourses; i++) {
            if (!inDegrees[i])
                nodes.push(i);
        }

        while (!nodes.empty()) {
            int front = nodes.front();
            nodes.pop();

            numCourses--;

            for (int n : adj[front]) {
                inDegrees[n]--;
                if (!inDegrees[n]) {
                    nodes.push(n);
                }
            }
        }

        return !numCourses;
    }
};