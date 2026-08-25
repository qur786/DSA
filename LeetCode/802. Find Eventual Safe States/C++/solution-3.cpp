class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> outDegrees(n, 0);
        vector<bool> safeNodes(n, false);
        queue<int> nodes;

        for (int i = 0; i < n; i++) {
            outDegrees[i] = graph[i].size();
            if (!outDegrees[i])
                nodes.push(i);

            for (int child : graph[i])
                adj[child].push_back(i);
        }

        while (!nodes.empty()) {
            int node = nodes.front();
            nodes.pop();
            safeNodes[node] = true;
            for (int child : adj[node]) {
                outDegrees[child]--;
                if (!outDegrees[child])
                    nodes.push(child);
            }
        }

        vector<int> answer;

        for (int i = 0; i < n; i++)
            if (safeNodes[i])
                answer.push_back(i);

        return answer;
    }
};