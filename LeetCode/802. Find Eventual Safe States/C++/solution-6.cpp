class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> outDegrees(n, 0);
        queue<int> nodes;
        vector<bool> answer(n, false);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                adj[graph[i][j]].push_back(i);
            }
            outDegrees[i] = graph[i].size();
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

        vector<int> result;
        result.reserve(n);

        for (int i = 0; i < n; i++)
            if (answer[i])
                result.push_back(i);

        return result;
    }
};