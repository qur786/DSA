class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int size = graph.size();
        vector<int> outDegrees(size, 0);
        vector<bool> safeNodes(size, false);
        vector<vector<int>> adj(size);
        vector<int> answer;
        answer.reserve(size);
        queue<int> nodes;

        for (int i = 0; i < size; i++) {
            outDegrees[i] += graph[i].size();
            for (int n : graph[i])
                adj[n].push_back(i);
        }

        for (int i = 0; i < size; i++)
            if (!outDegrees[i])
                nodes.push(i);

        while (!nodes.empty()) {
            int front = nodes.front();
            nodes.pop();
            safeNodes[front] = true;
            for (int n : adj[front]) {
                outDegrees[n]--;
                if (!outDegrees[n])
                    nodes.push(n);
            }
        }

        for (int i = 0; i < size; i++)
            if (safeNodes[i])
                answer.push_back(i);

        return answer;
    }
};