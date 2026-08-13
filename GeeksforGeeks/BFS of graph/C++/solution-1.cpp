class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int nodeCount = adj.size();
        vector<bool> visited(nodeCount, false);
        queue<int> nodes;
        vector<int> result;
        result.reserve(nodeCount);
        nodes.push(0);
        visited[0] = true;
        
        while(!nodes.empty()) {
            int size = nodes.size();
            
            for (int i = 0; i < size; i++) {
                int front = nodes.front(); nodes.pop();
                result.push_back(front);
                for (int n : adj[front]) {
                    if (!visited[n]) {
                        visited[n] = true;
                        nodes.push(n);
                    }
                }
            }
        }
        
        return result;
    }
};