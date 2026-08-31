class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegrees(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        queue<int> nodes;

        for (const auto& pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
            inDegrees[pre[1]]++;
        }

        for (int i = 0; i < numCourses; i++)
            if (!inDegrees[i])
                nodes.push(i);

        while (!nodes.empty()) {
            int front = nodes.front();
            nodes.pop();

            numCourses--;

            for (int child : adj[front]) {
                inDegrees[child]--;
                if (!inDegrees[child])
                    nodes.push(child);
            }
        }

        return numCourses == 0;
    }
};