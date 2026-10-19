class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> outDegrees(n, 0);
        vector<vector<int>> ingraph(n);
        vector<bool> answer(n, false);
        queue<int> nodes;

        for (int i = 0; i < n; i++) {
            outDegrees[i] = graph[i].size();

            for (int child : graph[i])
                ingraph[child].push_back(i);
        }

        for (int i = 0; i < n; i++)
            if (!outDegrees[i])
                nodes.emplace(i);
        int count = 0;
        while (!nodes.empty()) {
            auto node = nodes.front();
            nodes.pop();
            answer[node] = true;
            count += 1;

            for (int child : ingraph[node]) {
                outDegrees[child]--;
                if (!outDegrees[child])
                    nodes.emplace(child);
            }
        }

        vector<int> result;

        result.reserve(count);

        for (int i = 0; i < n; i++)
            if (answer[i])
                result.push_back(i);

        return result;
    }
};