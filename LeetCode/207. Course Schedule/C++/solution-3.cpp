class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int courses = numCourses;
        vector<int> inDegrees(numCourses, 0);
        queue<int> nodes;
        vector<vector<int>> adj(courses);

        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            inDegrees[pre[0]]++;
        }

        for (int i = 0; i < numCourses; i++)
            if (!inDegrees[i])
                nodes.push(i);

        while (!nodes.empty()) {
            int node = nodes.front();
            nodes.pop();
            courses--;

            for (int child : adj[node]) {
                inDegrees[child]--;
                if (!inDegrees[child])
                    nodes.push(child);
            }
        }

        return courses == 0;
    }
};