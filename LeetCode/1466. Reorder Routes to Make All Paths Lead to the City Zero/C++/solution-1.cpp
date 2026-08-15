class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int size = connections.size();
        int reorder = 0;
        vector<int> visited(n, false);
        vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());

        for (int i = 0; i < size; i++) {
            int left = connections[i][0], right = connections[i][1];
            adj[left].push_back(make_pair(right, 1));
            adj[right].push_back(make_pair(left, -1));
        }

        queue<int> nodes;
        nodes.push(0);
        visited[0] = true;

        while (!nodes.empty()) {
            int front = nodes.front();
            nodes.pop();
            int adjSize = adj[front].size();

            for (int j = 0; j < adjSize; j++) {
                int value = adj[front][j].first;
                int direction = adj[front][j].second;

                if (!visited[value]) {
                    nodes.push(value);
                    visited[value] = true;
                    if (direction == 1)
                        reorder++;
                }
            }
        }

        return reorder;
    }
};