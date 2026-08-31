class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> answer(n, 0), outDegrees(n, 0);
        vector<vector<int>> adj(n);
        queue<int> nodes;

        for (int i = 0; i < n; i++) {
            outDegrees[i] += graph[i].size();
            for (int child : graph[i]) {
                adj[child].push_back(i);
            }
        }

        for (int i = 0; i < n; i++)
            if (!outDegrees[i])
                nodes.push(i);

        while (!nodes.empty()) {
            int front = nodes.front();
            nodes.pop();
            answer[front] = 1;

            for (int child : adj[front]) {
                outDegrees[child]--;
                if (!outDegrees[child])
                    nodes.push(child);
            }
        }

        vector<int> result;
        result.reserve(n);

        for (int i = 0; i < n; i++)
            if (answer[i])
                result.push_back(i);

        return result;
    }
};