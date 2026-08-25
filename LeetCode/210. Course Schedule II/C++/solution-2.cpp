class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> answer;
        answer.reserve(numCourses);
        vector<int> inDegrees(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        queue<int> nodes;

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
            answer.push_back(node);

            for (int child : adj[node]) {
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