class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.empty())
            return true;
        vector<vector<int>> adj(numCourses);
        queue<int> nodes;
        vector<int> inDegrees(numCourses, 0);
        int count = numCourses;

        for (const auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
            inDegrees[edge[0]]++;
        }

        for (int i = 0; i < numCourses; i++)
            if (!inDegrees[i])
                nodes.push(i);

        while (!nodes.empty()) {
            auto front = nodes.front();
            nodes.pop();
            count--;

            for (int n : adj[front]) {
                inDegrees[n]--;
                if (!inDegrees[n])
                    nodes.push(n);
            }
        }

        return !count;
    }
};