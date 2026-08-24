class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.empty()) {
            vector<int> answer(numCourses, 0);
            iota(answer.begin(), answer.end(), 0);
            return answer;
        }

        vector<int> inDegrees(numCourses, 0), answer;
        answer.reserve(numCourses);
        vector<vector<int>> adj(numCourses);
        queue<int> nodes;

        for (const auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
            inDegrees[edge[0]]++;
        }

        for (int i = 0; i < numCourses; i++)
            if (!inDegrees[i])
                nodes.push(i);

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

        if (answer.size() == numCourses)
            return answer;

        return {};
    }
};