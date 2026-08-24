class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int size = graph.size();
        vector<int> outDegrees(size, 0);
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
            answer.push_back(front);
            for (int n : adj[front]) {
                outDegrees[n]--;
                if (!outDegrees[n])
                    nodes.push(n);
            }
        }

        sort(answer.begin(), answer.end());

        return answer;
    }
};