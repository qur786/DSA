class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> outDegrees(n, 0);
        vector<bool> answer(n, false);
        vector<int> result;
        result.reserve(n);
        queue<int> nodes;

        for (int i = 0; i < n; i++) {
            outDegrees[i] = graph[i].size();

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
            answer[front] = true;

            for (int child : adj[front]) {
                outDegrees[child]--;
                if (!outDegrees[child])
                    nodes.push(child);
            }
        }

        for (int i = 0; i < n; i++)
            if (answer[i])
                result.push_back(i);

        return result;
    }
};