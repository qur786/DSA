class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int size = graph.size();
        vector<int> result;
        result.reserve(size);
        vector<bool> safe(size, false);
        vector<int> outdegrees(size, 0);
        vector<vector<int>> ingraph(size);
        queue<int> nodes;

        for (int i = 0; i < size; i++) {
            int u = i;
            outdegrees[u] = graph[u].size();
            for (int v : graph[u]) {
                ingraph[v].push_back(u);
            }
        }

        for (int i = 0; i < size; i++) {
            if (!outdegrees[i])
                nodes.push(i);
        }

        while (!nodes.empty()) {
            auto front = nodes.front();
            nodes.pop();
            safe[front] = true;

            for (int child : ingraph[front]) {
                outdegrees[child]--;
                if (!outdegrees[child])
                    nodes.push(child);
            }
        }

        for (int i = 0; i < size; i++) {
            if (safe[i])
                result.push_back(i);
        }

        return result;
    }
};