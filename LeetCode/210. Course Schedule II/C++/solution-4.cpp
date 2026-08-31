class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> answer, inDegrees(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        answer.reserve(numCourses);
        queue<int> nodes;

        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            inDegrees[pre[0]]++;
        }

        for (int i = 0; i < numCourses; i++)
            if (!inDegrees[i])
                nodes.push(i);

        while (!nodes.empty()) {
            int front = nodes.front();
            nodes.pop();
            answer.push_back(front);

            for (int child : adj[front]) {
                inDegrees[child]--;
                if (!inDegrees[child]) {
                    nodes.push(child);
                }
            }
        }

        if (answer.size() != numCourses)
            return {};

        return answer;
    }
};