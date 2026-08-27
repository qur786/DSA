class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegrees(numCourses);
        vector<int> answer;
        answer.reserve(numCourses);
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
            answer.push_back(front);

            for (int n : adj[front]) {
                inDegrees[n]--;
                if (!inDegrees[n])
                    nodes.push(n);
            }
        }

        if (answer.size() != numCourses)
            return {};

        return answer;
    }
};